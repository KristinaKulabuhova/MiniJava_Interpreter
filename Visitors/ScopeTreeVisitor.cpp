#include "ScopeTreeVisitor.h"

#include <memory>

void ScopeTreeVisitor::Visit(Program *program) {
    cur_scope = new BaseScope();
    global_scope_ = cur_scope;
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->GetClasses()) {
        class_decl->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(AtExpr *expression) {
    expression->GetArray()->Accept(*this);
    expression->GetIndex()->Accept(*this);
}

void ScopeTreeVisitor::Visit(FieldExpr *expression) {
    if (!cur_scope->GetElement(expression->GetName())) {
        throw UndefRefError(expression->GetName());
    }
}

void ScopeTreeVisitor::Visit(NewArrExpr *expression) {
    expression->GetElement()->Accept(*this);
}

void ScopeTreeVisitor::Visit(NewCustomVarExpr *expression) {
    if (!cur_scope->GetElement(expression->GetName())) {
        throw UndefRefError(expression->GetName());
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
        throw UndefRefError(expression->GetName());
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

    if (!cur_scope->AddElement(expression->GetName(), new StClass(expression))) {
        throw MultiDeclError(expression->GetName());
    }
    for (auto& field : expression->GetVariable()) {
        field->Accept(*this);
    }
    for (auto& method : expression->GetMethods()) {
        method->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
    
}

void ScopeTreeVisitor::Visit(MethodInvocation *expression) {
    if (!cur_scope->GetElement(expression->name)) {
        throw UndefRefError(expression->name);
    }
}


void ScopeTreeVisitor::Visit(If* branching) {
    if (dynamic_cast<Block*>(branching->GetTrueBranch())) {
        auto old_scope = cur_scope;
        cur_scope = cur_scope->CreateChild();

        branching->GetTrueBranch()->Accept(*this);

        cur_scope = old_scope;
    }
    if (dynamic_cast<Block*>(branching->GetFalseBranch())) {
        auto old_scope = cur_scope;
        cur_scope = cur_scope->CreateChild();

        branching->GetFalseBranch()->Accept(*this);

        cur_scope = old_scope;
    }
}

void ScopeTreeVisitor::Visit(While* expression) {
    if (dynamic_cast<Block*>(expression->GetCycleBody())) {
        auto old_scope = cur_scope;
        cur_scope = cur_scope->CreateChild();

        expression->GetCycleBody()->Accept(*this);

        cur_scope = old_scope;
    }
}


void ScopeTreeVisitor::Visit(MethodDeclaration *expression) {
    if (!cur_scope->AddElement(expression->GetName(), new StFunction(expression))) {
        throw MultiDeclError(expression->GetName());
    }
    auto old_scope = cur_scope;
    cur_scope = cur_scope->CreateChild();

    if (expression->GetFormals()) {
        for (const auto &argument : expression->GetFormals()->GetVariables()) {
            if (!cur_scope->AddElement(expression->GetName(), new StVariable(*argument))) {
                throw MultiDeclError(argument->GetName());
            }
        }
    }
    expression->GetCode()->Accept(*this);

    cur_scope = old_scope;
    
}

void ScopeTreeVisitor::Visit(Println *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(Return *expression) {
    expression->GetExpression()->Accept(*this);
}

void ScopeTreeVisitor::Visit(VariableDeclaration *expression) {
    if (!cur_scope->AddElement(expression->GetName(), new StVariable(*expression->GetType()))) {
        throw MultiDeclError(expression->GetName());
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
    auto old_scope = cur_scope;
    cur_scope = cur_scope->CreateChild();

    expression->GetExecCode()->Accept(*this);

    cur_scope = old_scope;
}

void ScopeTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->GetProgramLines()) {
        program_block->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(Formals */*formals*/) {

}
