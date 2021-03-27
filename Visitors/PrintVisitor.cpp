#include "PrintVisitor.h"

int PrintVisitor::Visit(AtExpr *expression) {
    expression->array->Accept(*this);
    std::cout << " [ ";
    expression->index->Accept(*this);
    std::cout << " ]";
    return 0;
}

int PrintVisitor::Visit(FieldExpr *expression) {
    std::cout << "FIELD_EXPR(" << expression->name;
    if (expression->index) {
        std::cout << ", ";
        expression->index->Accept(*this);
    }
    std::cout << ")";
    return 0;
}

int PrintVisitor::Visit(NewArrExpr *expression) {
    std::cout << "NEW_ARR_EXPR(";
    switch (expression->simple_type) {
        case int_t: {
            std::cout << "int_t";
            break;
        }
        case bool_t: {
            std::cout << "bool_t";
            break;
        }
        case void_t: {
            std::cout << "void_t";
            break;
        }
        default: {
            std::cout << "custom_t";
            break;
        }
    }
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
    std::abort();
}

int PrintVisitor::Visit(For *expression) {
    std::abort();
}

int PrintVisitor::Visit(If *branching) {
    printTabs();
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
    printTabs();
    std::cout << "WHILE (";
    expression->statement->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->cycle_body->Accept(*this);
    --tabs_counter_;
    return 0;
}

int PrintVisitor::Visit(Lvalue *expression) {
    printTabs();
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
    return 0;
}

int PrintVisitor::Visit(Println *expression) {
    return 0;
}

int PrintVisitor::Visit(Return *expression) {
    return 0;
}

int PrintVisitor::Visit(VariableDeclaration *expression) {
    return 0;
}

int PrintVisitor::Visit(AssertExpr *expression) {
    return 0;
}

int PrintVisitor::Visit(Assignment *assignment) {
    return 0;
}

int PrintVisitor::Visit(Block *expression) {
    return 0;
}

int PrintVisitor::Visit(ExecCode *expression) {
    return 0;
}

int PrintVisitor::Visit(Program *program) {
    return 0;
}

void PrintVisitor::printTabs() const {
    for (size_t i = 0; i < tabs_counter_; ++i) {
        std::cout << "\t";
    }
}


