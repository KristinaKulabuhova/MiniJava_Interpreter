#include "PrintVisitor.h"

void PrintVisitor::Visit(AtExpr *expression) {
    expression->GetArray()->Accept(*this);
    std::cout << " [ ";
    expression->GetIndex()->Accept(*this);
    std::cout << " ]";
    
}

void PrintVisitor::Visit(FieldExpr *expression) {
    std::cout << "THIS." << expression->GetName();
}

void PrintVisitor::Visit(NewArrExpr *expression) {
    std::cout << "NEW_ARR_EXPR(";
    PrintSimpleType(expression->GetType(), true);
    std::cout << ", ";
    expression->GetElement()->Accept(*this);
    std::cout << ")";
    
}

void PrintVisitor::Visit(NewCustomVarExpr *expression) {
    std::cout << "NEW_CUSTOM_VAR_EXPR(" << expression->GetName() << ")";
    
}

void PrintVisitor::Visit(AndExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << " AND ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(NotExpr *expression) {
    std::cout << "NOT ";
    expression->GetExpression()->Accept(*this);
    
}

void PrintVisitor::Visit(OrExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << " OR ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(AddExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << " PLUS ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(ModExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "MOD ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(MulExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "MUL ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(DivExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "DIV ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(SubtractExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << " SUBTRACT ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(EqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "EQ ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(GEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "GEQ ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(GreaterExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "GE ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(NEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "NEQ ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(LEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "LEQ ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(LessExpr *expression) {
    expression->GetLeft()->Accept(*this);
    std::cout << "LE ";
    expression->GetRight()->Accept(*this);
    
}

void PrintVisitor::Visit(IdentExpr *expression) {
    std::cout << "IDENT_EXPR(" << expression->GetName() << ")";
    
}

void PrintVisitor::Visit(LengthExpr *expression) {
    std::cout << "LENGTH_EXPR(";
    expression->GetArray()->Accept(*this);
    std::cout << ")";
    
}

void PrintVisitor::Visit(NumExpr *expression) {
    std::cout << "NUM_EXPR(" << expression->GetValue() << ")";
    
}

void PrintVisitor::Visit(FalseExpr */*expression*/) {
    std::cout << "FALSE";
    
}

void PrintVisitor::Visit(TrueExpr* /*expression*/) {
    std::cout << "TRUE";
    
}

void PrintVisitor::Visit(Class *expression) {
    printTabs();
    std::cout << "CLASS(" << expression->GetName();
    if (!expression->GetParent().empty()) {
        std::cout << ", derived from " << expression->GetParent();
    }
    std::cout << "):\n";
    ++tabs_counter_;
    printTabs();
    std::cout << "Methods:\n";
    ++tabs_counter_;
    for (auto& p_method : expression->GetMethods()) {
        p_method->Accept(*this);
    }
    --tabs_counter_;
    printTabs();
    std::cout << "Fields:\n";
    ++tabs_counter_;
    for (auto& p_field : expression->GetVariable()) {
        p_field->Accept(*this);
    }
    --tabs_counter_;
    --tabs_counter_;
}

void PrintVisitor::Visit(MainClass *expression) {
    Visit(dynamic_cast<Class*>(expression));
    
}

void PrintVisitor::Visit(MethodInvocation *expression) {
    if (expression->callable_expr_) {
        expression->callable_expr_->Accept(*this);
    }
    std::cout << " POvoid " << expression->name_ << "(";
    if (expression->arguments_) {
        expression->arguments_->GetExpr().front()->Accept(*this);
        for (size_t i = 1; i < expression->arguments_->GetExpr().size(); ++i) {
            std::cout << ", ";
            expression->arguments_->GetExpr()[i]->Accept(*this);
        }
    }
    std::cout << ")";
    
}

void PrintVisitor::Visit(If *branching) {
    std::cout << "IF (";
    branching->GetStatement()->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    branching->GetTrueBranch()->Accept(*this);
    if (branching->GetFalseBranch()) {
        --tabs_counter_;
        printTabs();
        std::cout << "ELSE:\n";
        ++tabs_counter_;
        branching->GetFalseBranch()->Accept(*this);
    }
    --tabs_counter_;
    
}

void PrintVisitor::Visit(While *expression) {
    std::cout << "WHILE (";
    expression->GetStatement()->Accept(*this);
    std::cout << "):\n";
    ++tabs_counter_;
    expression->GetCycleBody()->Accept(*this);
    --tabs_counter_;
    
}

void PrintVisitor::Visit(MethodDeclaration *expression) {
    printTabs();
    printVarTypeStr(expression->GetType());
    std::cout << " " << expression->GetName() << "(";
    if (expression->GetFormals()) {
        expression->GetFormals()->Accept(*this);
    }
    std::cout << "):\n";
    ++tabs_counter_;
    expression->GetCode()->Accept(*this);
    --tabs_counter_;
}

void PrintVisitor::Visit(Println *expression) {
    std::cout << "PRINTLN(";
    expression->GetExpression()->Accept(*this);
    std::cout << ");";
}

void PrintVisitor::Visit(Return *expression) {
    std::cout << "RETURN ";
    expression->GetExpression()->Accept(*this);
    
}

void PrintVisitor::Visit(VariableDeclaration *expression) {
    printVarTypeStr(expression->GetType());
    std::cout << " " << expression->GetName() << ";";
}

void PrintVisitor::Visit(AssertExpr *expression) {
    std::cout << "ASSERT(";
    expression->GetExpression()->Accept(*this);
    std::cout << ")";
    
}

void PrintVisitor::Visit(Assignment *assignment) {
    std::cout << "ASSIGN TO ";
    assignment->GetTo()->Accept(*this);
    std::cout << " FROM (";
    assignment->GetFrom()->Accept(*this);
    std::cout << ");";
}

void PrintVisitor::Visit(Block *expression) {
    printTabs();
    std::cout << "NEW_BLOCK_BEGIN:\n";
    ++tabs_counter_;
    expression->GetExecCode()->Accept(*this);
    --tabs_counter_;
    printTabs();
    std::cout << "BLOCK_END\n";
    
}

void PrintVisitor::Visit(ExecCode *expression) {
    for (auto& line : expression->GetProgramLines()) {
        if (!dynamic_cast<Block*>(line)) {
            printTabs();
        }
        line->Accept(*this);
        std::cout << "\n";
    }
    
}

void PrintVisitor::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& decl : program->class_decl_list->GetClasses()) {
        decl->Accept(*this);
    }
}

void PrintVisitor::printTabs() const {
    for (size_t i = 0; i < tabs_counter_; ++i) {
        std::cout << "\t";
    }
}

void PrintVisitor::Visit(Formals *formals) {
    for (const auto& var : formals->GetVariables()) {
        printVarTypeStr(var);
        std::cout << " " << var->GetName();
    }
    
}

void PrintVisitor::printVarTypeStr(VarTypeStr* var_type_str) {
    switch (var_type_str->GetType()) {
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
    if (var_type_str->GetArray()) {
        std::cout << "[]";
    }
}

void PrintVisitor::PrintSimpleType(SimpleType* simple_type, bool array) {
    switch (simple_type->GetId()) {
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
            std::cout << simple_type->GetName() << "CUSTOM";
        }
    }
    if (array) {
        std::cout << "[]";
    }    
}