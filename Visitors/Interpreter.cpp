#include "Interpreter.h"

Interpreter::Interpreter(const std::vector<VarDeclList*>& var_declarations) {
    for (const auto& var_decl_list : var_declarations) {
        for (const auto &var_name : var_decl_list->var_names) {
            if (var_value.find(var_name) != var_value.end()) {
                throw MultiDeclError(var_name);
            }
            if (var_decl_list->type == integer) {
                var_value[var_name] = 0;
            } else if (var_decl_list->type == string) {
                var_value[var_name] = std::string();
            }
        }
    }
}

std::variant<int, std::string> Interpreter::Visit(IdentExpr* expression) {
    try {
        var_value[expression->var_name_];
    } catch (const std::out_of_range& exception) {
        throw UndefRefError(expression->var_name_);
    }
    return var_value[expression->var_name_];
}

std::variant<int, std::string> Interpreter::Visit(AddExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("+", true, first_res, second_res);
    return std::get<int>(first_res) + std::get<int>(second_res);
}

var_t Interpreter::Visit(DivExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("/", true, first_res, second_res);
    return std::get<int>(first_res) / std::get<int>(second_res);
}

var_t Interpreter::Visit(ModExpr *expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("mod", true, first_res, second_res);
    return std::get<int>(first_res) % std::get<int>(second_res);
}

var_t Interpreter::Visit(MulExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("*", true, first_res, second_res);
    return std::get<int>(first_res) * std::get<int>(second_res);
}

var_t Interpreter::Visit(SubtractExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("-", true, first_res, second_res);
    return std::get<int>(first_res) - std::get<int>(second_res);
}


var_t Interpreter::Visit(ConstExpr *expression) {
    return expression->value;
}

void Interpreter::Visit(Assignment* assignment) {
    auto res = assignment->expression->Accept(*this);
    CheckOperationCorrectness("=", true, var_value[assignment->var_name_], res);
    var_value[assignment->var_name_] = res;
}

void Interpreter::Visit(ExecCode* code) {
    for (const auto& program_line : code->program_lines_) {
        program_line->Accept(*this);
    }
}

void Interpreter::Visit(If* branching) {
    auto res = branching->statement->Accept(*this);
    CheckBoolCorrectness(res);
    if (std::get<int>(res)  != 0) {
        branching->true_branch->Accept(*this);
    } else if (branching->false_branch) {
        branching->false_branch->Accept(*this);
    }
}

void Interpreter::Visit(While* while_cycle) {
    CheckBoolCorrectness(while_cycle->statement->Accept(*this));
    while (std::get<int>(while_cycle->statement->Accept(*this))) {
        while_cycle->cycle_body->Accept(*this);
    }
}

void Interpreter::Visit(Read* read_module) {
    std::string buffer;
    std::cin >> buffer;
    std::pair<int, std::string> type;
    GetType(type, var_value[read_module->var_name]);
    if (type.first == integer) {
        var_value[read_module->var_name] = std::stoi(buffer);
    } else if (type.first == string) {
        var_value[read_module->var_name] = std::move(buffer);
    }
}

void Interpreter::Visit(For* for_cycle) {
    auto lower_res = for_cycle->lower_bound->Accept(*this);
    auto upper_res = for_cycle->upper_bound->Accept(*this);
    CheckIntCorrectness(var_value[for_cycle->var_name]);
    CheckIntCorrectness(lower_res);
    CheckIntCorrectness(upper_res);
    for (var_value[for_cycle->var_name] = std::get<int>(lower_res);
         std::get<int>(var_value[for_cycle->var_name]) <= std::get<int>(upper_res);
         var_value[for_cycle->var_name] = std::get<int>(var_value[for_cycle->var_name]) + 1) {
        for_cycle->cycle_body->Accept(*this);
    }
}

//---------------------------------------------- Logic operators ----------------------------------------------//

var_t Interpreter::Visit(LessExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("<", true, l_res, r_res);
    return std::get<int>(l_res) < std::get<int>(r_res);
}

var_t Interpreter::Visit(GreaterExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness(">", true, l_res, r_res);
    return std::get<int>(l_res) > std::get<int>(r_res);
}







void Interpreter::CheckOperationCorrectness(const std::string &operation, bool only_for_numbers,
                                            const var_t &first_val, const var_t &second_val) {
    if (first_val.index() == second_val.index() && !only_for_numbers) {
        return;
    } else if (first_val.index() == second_val.index() && first_val.index() == 0) {
        return;
    }
    std::pair<int, std::string> first_type, second_type;
    GetType(first_type, first_val);
    GetType(second_type, second_val);
    throw WrongBinaryOperandsError("+", first_type.second, second_type.second);
}

void Interpreter::CheckBoolCorrectness(const var_t &val) {
    if (val.index() != 0) {
        std::pair<int, std::string> type;
        GetType(type, val);
        throw ExpectedBoolError(type.second);
    }
}

void Interpreter::GetType(std::pair<int, std::string>& type, const var_t &val) {
    switch (val.index()) {
        case 0: {
            type.second = "integer";
            type.first = integer;
            break;
        }
        case 1: {
            type.second = "string";
            type.first = string;
            break;
        }
        default: {
            type.second = "unknown type";
            type.first = unknown;
            break;
        }
    }
}

void Interpreter::Visit(Write *write_module) {
    std::pair<int, std::string> type;
    auto res = write_module->expression->Accept(*this);
    GetType(type, res);
    switch (type.first) {
        case integer: {
            std::cout << std::get<int>(res) << '\n';
            break;
        }
        case string: {
            std::cout << std::get<std::string>(res) << '\n';
            break;
        }
        default: {
            std::cout << "<unknown type>\n";
        }
    }
}

void Interpreter::CheckIntCorrectness(const var_t &val) {
    std::pair<int, std::string> type;
    GetType(type, val);
    if (type.first != integer) {
        throw ExpectedIntError(type.second);
    }
}

var_t Interpreter::Visit(LEqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("<=", true, l_res, r_res);
    return std::get<int>(l_res) <= std::get<int>(r_res);
}

var_t Interpreter::Visit(GeqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness(">=", true, l_res, r_res);
    return std::get<int>(l_res) >= std::get<int>(r_res);
}

var_t Interpreter::Visit(EqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("=", true, l_res, r_res);
    return std::get<int>(l_res) == std::get<int>(r_res);
}

var_t Interpreter::Visit(NEqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("<>", true, l_res, r_res);
    return std::get<int>(l_res) != std::get<int>(r_res);
}

var_t Interpreter::Visit(AndExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("and", true, l_res, r_res);
    return std::get<int>(l_res) && std::get<int>(r_res);
}

var_t Interpreter::Visit(OrExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    CheckOperationCorrectness("or", true, l_res, r_res);
    return std::get<int>(l_res) || std::get<int>(r_res);
}

var_t Interpreter::Visit(NotExpr *expression) {
    auto res = expression->p_expr->Accept(*this);
    CheckBoolCorrectness(res);
    return !std::get<int>(res);
}


