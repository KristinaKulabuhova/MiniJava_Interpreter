#include "PrintVisitor.h"

int PrintVisitor::Visit(AtExpr *expression) {
    expression->array->Accept(*this);
    std::cout << " [ ";
    expression->index->Accept(*this);
    std::cout << " ]";
    return 0;
}

int PrintVisitor::Visit(FieldExpr *expression) {
    std::cout << "THIS." << expression->name;
    return 0;
}

int PrintVisitor::Visit(NewArrExpr *expression) {
    std::cout << "NEW_ARR_EXPR(";
    printVarTypeStr(VarTypeStr(expression->simple_type));
    std::cout << ", ";
    expression->n_elements->Accept(*this);
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(NewCustomVarExpr *expression) {
    std::cout << "NEW_CUSTOM_VAR_EXPR(" << expression->class_name << ")";
    return 0;
}

int PrintVisitor::Visit(AndExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << " AND ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(NotExpr *expression) {
    std::cout << "NOT ";
    expression->p_expr->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(OrExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << " OR ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(AddExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "PLUS ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(ModExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "MOD ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(MulExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "MUL ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(DivExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "DIV ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(SubtractExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "SUBTRACT ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(EqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "EQ ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(GEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "GEQ ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(GreaterExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "GE ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(NEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "NEQ ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(LEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "LEQ ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(LessExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "LE ";
    expression->p_rhs->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(IdentExpr *expression) {
    std::cout << "IDENT_EXPR(" << expression->var_name_ << ")";
    return 0;
}

int PrintVisitor::Visit(LengthExpr *expression) {
    std::cout << "LENGTH_EXPR(";
    expression->array->Accept(*this);
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(VarExpr *expression) {
    std::cout << "VAR_EXPR(" << expression->name;
    if (expression->index) {
        std::cout << ", ";
        expression->index->Accept(*this);
    }
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(NumExpr *expression) {
    std::cout << "NUM_EXPR(" << expression->value << ")";
    return 0;
}

int PrintVisitor::Visit(ThisExpr *expression) {
    std::cout << "THIS";
    return 0;
}

int PrintVisitor::Visit(FalseExpr *expression) {
    std::cout << "FALSE";
    return 0;
}

int PrintVisitor::Visit(TrueExpr *expression) {
    std::cout << "TRUE";
    return 0;
}

int PrintVisitor::Visit(Class *expression) {
    printTabs();
    std::cout << "CLASS(" << expression->name_;
    if (!expression->parent_class_.empty()) {
        std::cout << ", derived from " << expression->parent_class_;
    }
    std::cout << "):\n";
    ++tabs_counter_;
    printTabs();
    std::cout << "Methods:\n";
    ++tabs_counter_;
    for (auto& p_method : expression->methods_) {
        p_method->Accept(*this);
    }
    --tabs_counter_;
    printTabs();
    std::cout << "Fields:\n";
    ++tabs_counter_;
    for (auto& p_field : expression->variables_) {
        p_field->Accept(*this);
    }
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(MainClass *expression) {
    Visit(dynamic_cast<Class*>(expression));
    return 0;
}

int PrintVisitor::Visit(MethodInvocation *expression) {
    expression->callable_expr->Accept(*this);
    std::cout << " POINT " << expression->name << "(";
    if (!expression->arguments->expressions.empty()) {
        expression->arguments->expressions.front()->Accept(*this);
    }
    for (size_t i = 1; i < expression->arguments->expressions.size(); ++i) {
        std::cout << ", ";
        expression->arguments->expressions[i]->Accept(*this);
    }
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(For *expression) {
    std::cout << "FOR(" << expression->var_name << " FROM ";
    expression->lower_bound->Accept(*this);
    std::cout << " TO ";
    expression->upper_bound->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->cycle_body->Accept(*this);
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(If *branching) {
    std::cout << "IF (";
    branching->statement->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    branching->true_branch->Accept(*this);
    if (branching->false_branch) {
        --tabs_counter_;
        printTabs();
        std::cout << "ELSE:\n";
        ++tabs_counter_;
        branching->false_branch->Accept(*this);
    }
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(While *expression) {
    std::cout << "WHILE (";
    expression->statement->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->cycle_body->Accept(*this);
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(Lvalue *expression) {
    std::cout << "LVALUE(";
    if (std::holds_alternative<VarExpr*>(expression->lvalue)) {
        std::get<VarExpr*>(expression->lvalue)->Accept(*this);
    } else if (std::holds_alternative<FieldExpr*>(expression->lvalue)) {
        std::get<FieldExpr*>(expression->lvalue)->Accept(*this);
    }
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(MethodDeclaration *expression) {
    printVarTypeStr(expression->return_type_);
    std::cout << " " << expression->name_ << "(";
    expression->arguments_->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->exec_code_->Accept(*this);
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(Println *expression) {
    std::cout << "PRINTLN(";
    expression->expression->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(Return *expression) {
    std::cout << "RETURN ";
    expression->expression->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(VariableDeclaration *expression) {
    printVarTypeStr(expression->type_);
    std::cout << " " << expression->name_ << ";\n";
    return 0;
}

int PrintVisitor::Visit(AssertExpr *expression) {
    std::cout << "ASSERT(";
    expression->expression->Accept(*this);
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(Assignment *assignment) {
    std::cout << "ASSIGN TO ";
    assignment->to->Accept(*this);
    std::cout << " FROM ";
    assignment->from->Accept(*this);
    return 0;
}

int PrintVisitor::Visit(Block *expression) {
    std::cout << "NEW_BLOCK_BEGIN:\n";
    ++tabs_counter_;
    expression->exec_code->Accept(*this);
    --tabs_counter_;
    printTabs();
    std::cout << "BLOCK_END\n";
    return 0;
}

int PrintVisitor::Visit(ExecCode *expression) {
    for (auto& line : expression->program_lines_) {
        printTabs();
        line->Accept(*this);
        std::cout << "\n";
    }
    return 0;
}

int PrintVisitor::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& decl : program->class_decl_list->classes) {
        decl->Accept(*this);
    }
    return 0;
}

void PrintVisitor::printTabs() const {
    for (size_t i = 0; i < tabs_counter_; ++i) {
        std::cout << "\t";
    }
}

int PrintVisitor::Visit(Formals *formals) {
    if (!formals->variables.empty()) {
        printVarTypeStr(formals->variables.front().first);
        std::cout << " " << formals->variables.front().second;
    }
    for (size_t i = 1 ; i < formals->variables.size(); ++i) {
        std::cout << ", ";
        printVarTypeStr(formals->variables[i].first);
        std::cout << " " << formals->variables[i].second;
    }
    return 0;
}

void PrintVisitor::printVarTypeStr(const VarTypeStr &var_type_str) {
    switch (var_type_str.type) {
        case int_t: {
            std::cout << "INT";
        }
        case bool_t: {
            std::cout << "BOOLEAN";
        }
        case void_t: {
            std::cout << "VOID";
        }
        default: {
            std::cout << "CUSTOM";
        }
    }
    if (var_type_str.array) {
        std::cout << "[]";
    }
}