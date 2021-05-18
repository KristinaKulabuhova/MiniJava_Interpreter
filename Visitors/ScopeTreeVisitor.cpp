#include "ScopeTreeVisitor.h"

#include <memory>

void ScopeTreeVisitor::Visit(Program *program) {
    cur_scope = new BaseScope();
    global_scope_ = cur_scope;
    cur_scope->AddElement(program->main_class->GetName(), new StClass(program->main_class));
    cur_scope = cur_scope->CreateChild();
    for (auto& p_method : program->main_class->GetMethods()) {
        if (!cur_scope->AddElement(p_method->GetName(), new StFunction(p_method))) {
            MultiDeclError(p_method->GetName(), p_method->GetLoc());
        }
    }
    cur_scope = cur_scope->GetParent();
    for (auto& class_decl : program->class_decl_list->GetClasses()) {
        if (!cur_scope->AddElement(class_decl->GetName(), new StClass(class_decl))) {
            MultiDeclError(class_decl->GetName(), class_decl->GetLoc());
        }
        cur_scope = cur_scope->CreateChild();
        for (auto& p_method : class_decl->GetMethods()) {
            if (!cur_scope->AddElement(p_method->GetName(), new StFunction(p_method))) {
                MultiDeclError(p_method->GetName(), p_method->GetLoc());
            }
        }
        cur_scope = cur_scope->GetParent();
    }
    cur_scope = cur_scope->GetChild(0);
    program->main_class->Accept(*this);
    cur_scope = cur_scope->GetParent();
    for (size_t ind = 0; ind < program->class_decl_list->GetClasses().size(); ++ind) {
        cur_scope = cur_scope->GetChild(ind + 1);
        program->class_decl_list->GetClasses()[ind]->Accept(*this);
        cur_scope = cur_scope->GetParent();
    }
    for (auto & all_error : all_errors) {
        cur_scope = cur_scope->CreateChild();
        std::cout << all_error.second << " " << all_error.first << "\n";
        cur_scope = global_scope_;
    }
}

void ScopeTreeVisitor::Visit(AtExpr *expression) {
    expression->GetArray()->Accept(*this);
    expression->GetIndex()->Accept(*this);
}

void ScopeTreeVisitor::Visit(FieldExpr *expression) {
    if (!cur_scope->GetElement(expression->GetName())) {
        UndefRefError(expression->GetName(), expression->GetLoc());
    }
}

void ScopeTreeVisitor::Visit(NewArrExpr *expression) {
    expression->GetElement()->Accept(*this);
}

void ScopeTreeVisitor::Visit(NewCustomVarExpr *expression) {
    if (!cur_scope->GetElement(expression->GetName())) {
        UndefRefError(expression->GetName(), expression->GetLoc());
    }
}

void ScopeTreeVisitor::Visit(AndExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(NotExpr *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(OrExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(AddExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(ModExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(MulExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(DivExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(SubtractExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(EqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(GEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(GreaterExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(NEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(LEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(LessExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
}

void ScopeTreeVisitor::Visit(IdentExpr *expression) {
    if (!cur_scope->GetElement(expression->GetName())) {
        UndefRefError(expression->GetName(), expression->GetLoc());
    }
}

void ScopeTreeVisitor::Visit(LengthExpr *expression) {
    expression->GetArray()->Accept(*this);
}


void ScopeTreeVisitor::Visit(NumExpr */*expression*/) {
    
}


void ScopeTreeVisitor::Visit(FalseExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(TrueExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Class *expression) {

    for (auto& field : expression->GetVariable()) {
        field->Accept(*this);
    }
    for (auto& method : expression->GetMethods()) {
        cur_scope = cur_scope->CreateChild();
        method->Accept(*this);
        cur_scope = cur_scope->GetParent();
    }
    
}

void ScopeTreeVisitor::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
    
}

void ScopeTreeVisitor::Visit(MethodInvocation *expression) {
    if (!cur_scope->GetElement(expression->name_)) {
        UndefRefError(expression->name_, expression->BaseExpr::GetLoc());
    }
}


void ScopeTreeVisitor::Visit(If* branching) {
    branching->GetTrueBranch()->Accept(*this);
    if (branching->GetFalseBranch()) {
        branching->GetFalseBranch()->Accept(*this);
    }
}

void ScopeTreeVisitor::Visit(While* expression) {
    expression->GetCycleBody()->Accept(*this);
}


void ScopeTreeVisitor::Visit(MethodDeclaration *expression) {
    if (expression->GetFormals()) {
        for (const auto &argument : expression->GetFormals()->GetVariables()) {
            if (!cur_scope->AddElement(argument->GetName(), new StVariable(*argument))) {
                MultiDeclError(argument->GetName(), expression->GetLoc());
            }
        }
    }
    expression->GetCode()->Accept(*this);
    
}

void ScopeTreeVisitor::Visit(Println *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(Return *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(VariableDeclaration *expression) {
    if (!cur_scope->AddElement(expression->GetName(), new StVariable(*expression->GetType()))) {
        MultiDeclError(expression->GetName(), expression->GetLoc());
    }
}

void ScopeTreeVisitor::Visit(AssertExpr *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(Assignment *assignment) {
    assignment->GetFrom()->Accept(*this);
    assignment->GetTo()->Accept(*this);
}

void ScopeTreeVisitor::Visit(Block *expression) {
    cur_scope = cur_scope->CreateChild();

    expression->GetExecCode()->Accept(*this);

    cur_scope = cur_scope->GetParent();
}

void ScopeTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->GetProgramLines()) {
        program_block->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(Formals */*formals*/) {

}
