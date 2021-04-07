#include "Interpreter.h"

Interpreter::Interpreter(std::shared_ptr<ScopeLayerTree> tree): tree_(tree) {
    offsets_.push(0);
    current_layer_ = tree_->root_;
}

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
    return std::get<int>(first_res) + std::get<int>(second_res);
}

int Interpreter::Visit(DivExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    return std::get<int>(first_res) / std::get<int>(second_res);
}

int Interpreter::Visit(ModExpr *expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    return std::get<int>(first_res) % std::get<int>(second_res);
}

int Interpreter::Visit(MulExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    return std::get<int>(first_res) * std::get<int>(second_res);
}

int Interpreter::Visit(SubtractExpr* expression) {
    auto first_res = expression->p_lhs->Accept(*this);
    auto second_res = expression->p_rhs->Accept(*this);
    return std::get<int>(first_res) - std::get<int>(second_res);
}

int Visit(FalseExpr* expression) {
    expression->Accept(*this);
    return 0;
}

int Visit(TrueExpr* expression) {
    expression->Accept(*this);
    return 1;
}

int Interpreter::Visit(LengthExpr *expression) {
    auto res = expression->array->Accept(*this);
    return std::get<int>(res);  
}

int Interpreter::Visit(FieldExpr *expression) {
    auto res = expression->array->Accept(*this);
    return std::get<int>(res);  
}

int Visit(ThisExpr* expression) { 
}

int Visit(AssertExpr* expression) { 
    auto res = expression->expression->Accept(*this);
    return assert(res);
}

int Interpreter::Visit(VarExpr *expression) {
    expression->name->Accept(*this); 
    if (expression->index != nullptr) {
        expression->index->Accept(*this);
    }
    return expression->name;
}

void Interpreter::Visit(ScopeAssignmentList* list) {
    std::cout << "Going inside" << std::endl;

    current_layer_ = current_layer_->GetChild(offsets_.top());

    offsets_.push(0);
    list->statement_list->Accept(this);

    offsets_.pop();
    size_t index = offsets_.top();

    offsets_.pop();
    offsets_.push(index + 1);

    current_layer_ = current_layer_->GetParent();
}

void Interpreter::Visit(Assignment* assignment) {
    auto res = assignment->expression->Accept(*this);
    var_value[assignment->var_name_] = res;

    current_layer_->Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
}

void Interpreter::Visit(ExecCode* code) {
    for (const auto& program_line : code->program_lines_) {
        program_line->Accept(*this);
    }
}

void Interpreter::Visit(If* branching) {
    auto res = branching->statement->Accept(*this);
    if (std::get<int>(res)  != 0) {
        branching->true_branch->Accept(*this);
    } else if (branching->false_branch) {
        branching->false_branch->Accept(*this);
    }

    current_layer_->Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
}

void Interpreter::Visit(While* while_cycle) {
    while (std::get<int>(while_cycle->statement->Accept(*this))) {
        while_cycle->cycle_body->Accept(*this);
    }
}

void Interpreter::Visit(For* for_cycle) {
    auto lower_res = for_cycle->lower_bound->Accept(*this);
    auto upper_res = for_cycle->upper_bound->Accept(*this);
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
    return std::get<int>(l_res) < std::get<int>(r_res);
}

var_t Interpreter::Visit(GreaterExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) > std::get<int>(r_res);
}

void Interpreter::Visit(Println *expression) {
    auto res = write_module->expression->Accept(*this);
    std::cout << std::get<int>(res) << '\n';
}

int Interpreter::Visit(LEqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) <= std::get<int>(r_res);
}

int Interpreter::Visit(GeqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) >= std::get<int>(r_res);
}

int Interpreter::Visit(EqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) == std::get<int>(r_res);
}

int Interpreter::Visit(NEqExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) != std::get<int>(r_res);
}

int Interpreter::Visit(AndExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) && std::get<int>(r_res);
}

int Interpreter::Visit(OrExpr *expression) {
    auto l_res = expression->p_lhs->Accept(*this);
    auto r_res = expression->p_rhs->Accept(*this);
    return std::get<int>(l_res) || std::get<int>(r_res);
}

int Interpreter::Visit(NotExpr *expression) {
    auto res = expression->p_expr->Accept(*this);
    return !std::get<int>(res);
}


