#include "PrintVisitor.h"

void PrintVisitor::Visit(AtExpr *expression) {
    expression->array->Accept(*this);
    std::cout << " [ ";
    expression->index->Accept(*this);
    std::cout << " ]";
    
}

void PrintVisitor::Visit(FieldExpr *expression) {
    std::cout << "THIS." << expression->name;
}

void PrintVisitor::Visit(NewArrExpr *expression) {
    std::cout << "NEW_ARR_EXPR(";
    PrintSimpleType(expression->simple_type, true);
    std::cout << ", ";
    expression->n_elements->Accept(*this);
    std::cout << ")";
    
}

void PrintVisitor::Visit(NewCustomVarExpr *expression) {
    std::cout << "NEW_CUSTOM_VAR_EXPR(" << expression->class_name << ")";
    
}

void PrintVisitor::Visit(AndExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << " AND ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(NotExpr *expression) {
    std::cout << "NOT ";
    expression->p_expr->Accept(*this);
    
}

void PrintVisitor::Visit(OrExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << " OR ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(AddExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << " PLUS ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(ModExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "MOD ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(MulExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "MUL ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(DivExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "DIV ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(SubtractExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "SUBTRACT ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(EqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "EQ ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(GEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "GEQ ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(GreaterExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "GE ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(NEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "NEQ ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(LEqExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "LEQ ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(LessExpr *expression) {
    expression->p_lhs->Accept(*this);
    std::cout << "LE ";
    expression->p_rhs->Accept(*this);
    
}

void PrintVisitor::Visit(IdentExpr *expression) {
    std::cout << "IDENT_EXPR(" << expression->var_name_ << ")";
    
}

void PrintVisitor::Visit(LengthExpr *expression) {
    std::cout << "LENGTH_EXPR(";
    expression->array->Accept(*this);
    std::cout << ")";
    
}

// void PrintVisitor::Visit(VarExpr *expression) {
//     std::cout << "VAR_EXPR(" << expression->name;
//     if (expression->index) {
//         std::cout << ", ";
//         expression->index->Accept(*this);
//     }
//     std::cout << ")";
    
// }

void PrintVisitor::Visit(NumExpr *expression) {
    std::cout << "NUM_EXPR(" << expression->value << ")";
    
}

void PrintVisitor::Visit(FalseExpr */*expression*/) {
    std::cout << "FALSE";
    
}

void PrintVisitor::Visit(TrueExpr* /*expression*/) {
    std::cout << "TRUE";
    
}

void PrintVisitor::Visit(Class *expression) {
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
    
}

void PrintVisitor::Visit(MainClass *expression) {
    Visit(dynamic_cast<Class*>(expression));
    
}

void PrintVisitor::Visit(MethodInvocation *expression) {
    expression->callable_expr->Accept(*this);
    std::cout << " POvoid " << expression->name << "(";
    if (!expression->arguments->expressions.empty()) {
        expression->arguments->expressions.front()->Accept(*this);
    }
    for (size_t i = 1; i < expression->arguments->expressions.size(); ++i) {
        std::cout << ", ";
        expression->arguments->expressions[i]->Accept(*this);
    }
    std::cout << ")";
    
}

void PrintVisitor::Visit(If *branching) {
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
    
}

void PrintVisitor::Visit(While *expression) {
    std::cout << "WHILE (";
    expression->statement->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->cycle_body->Accept(*this);
    --tabs_counter_;
    
}

void PrintVisitor::Visit(MethodDeclaration *expression) {
    printTabs();
    printVarTypeStr(expression->return_type_);
    std::cout << " " << expression->name_ << "(";
    if (expression->arguments_) {
        expression->arguments_->Accept(*this);
    }
    std::cout << "):\n";
    ++tabs_counter_;
    expression->exec_code_->Accept(*this);
    --tabs_counter_;
    
}

void PrintVisitor::Visit(Println *expression) {
    std::cout << "PRINTLN(";
    expression->expression->Accept(*this);
    std::cout << ");";
}

void PrintVisitor::Visit(Return *expression) {
    std::cout << "RETURN ";
    expression->expression->Accept(*this);
    
}

void PrintVisitor::Visit(VariableDeclaration *expression) {
    printVarTypeStr(expression->type_);
    std::cout << " " << expression->name_ << ";";
}

void PrintVisitor::Visit(AssertExpr *expression) {
    std::cout << "ASSERT(";
    expression->expression->Accept(*this);
    std::cout << ")";
    
}

void PrintVisitor::Visit(Assignment *assignment) {
    std::cout << "ASSIGN TO ";
    assignment->to->Accept(*this);
    std::cout << " FROM (";
    assignment->from->Accept(*this);
    std::cout << ");";
}

void PrintVisitor::Visit(Block *expression) {
    std::cout << "NEW_BLOCK_BEGIN:\n";
    ++tabs_counter_;
    expression->exec_code->Accept(*this);
    --tabs_counter_;
    printTabs();
    std::cout << "BLOCK_END\n";
    
}

void PrintVisitor::Visit(ExecCode *expression) {
    for (auto& line : expression->program_lines_) {
        printTabs();
        line->Accept(*this);
        std::cout << "\n";
    }
    
}

void PrintVisitor::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& decl : program->class_decl_list->classes) {
        decl->Accept(*this);
    }
    
}

void PrintVisitor::printTabs() const {
    for (size_t i = 0; i < tabs_counter_; ++i) {
        std::cout << "\t";
    }
}

void PrintVisitor::Visit(Formals *formals) {
    for (const auto& var : formals->variables) {
        printVarTypeStr(var);
        std::cout << " " << var->name_;
    }
    
}

void PrintVisitor::printVarTypeStr(VarTypeStr* var_type_str) {
    switch (var_type_str->type) {
        case int_t: {
            std::cout << "INT";
            break;
        }
        case bool_t: {
            std::cout << "BOOLEAN";
            break;
        }
        case void_t: {
            std::cout << "VOID";
            break;
        }
        default: {
            std::cout << "CUSTOM";
        }
    }
    if (var_type_str->array) {
        std::cout << "[]";
    }
}

void PrintVisitor::PrintSimpleType(SimpleType* simple_type, bool array) {
    switch (simple_type->type_id) {
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
            std::cout << simple_type->type_name_ << "CUSTOM";
        }
    }
    if (array) {
        std::cout << "[]";
    }    
}