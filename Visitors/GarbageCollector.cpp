#include "GarbageCollector.h"

void GarbageCollector::Visit(AtExpr *expression) {
    expression->GetArray()->Accept(*this);
    expression->GetIndex()->Accept(*this);
    delete expression->GetArray();
    delete expression->GetIndex();
}

void GarbageCollector::Visit(FieldExpr */*expression*/) {}

void GarbageCollector::Visit(NewArrExpr *expression) {
    expression->GetElement()->Accept(*this);
    delete expression->GetType();
    delete expression->GetElement();
}

void GarbageCollector::Visit(NewCustomVarExpr */*expression*/) {}

void GarbageCollector::Visit(AndExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(NotExpr *expression) {
    expression->GetExpression()->Accept(*this);
    delete expression->GetExpression();
}

void GarbageCollector::Visit(OrExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(AddExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(ModExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(MulExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(DivExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(SubtractExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(EqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(GEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(GreaterExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(NEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(LEqExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(LessExpr *expression) {
    expression->GetLeft()->Accept(*this);
    expression->GetRight()->Accept(*this);
    delete expression->GetLeft();
    delete expression->GetRight();
}

void GarbageCollector::Visit(IdentExpr */*expression*/) {}

void GarbageCollector::Visit(LengthExpr *expression) {
    expression->GetArray()->Accept(*this);
    delete expression->GetArray();
}

void GarbageCollector::Visit(NumExpr* /*expression*/) {}

void GarbageCollector::Visit(FalseExpr */*expression*/) {}

void GarbageCollector::Visit(TrueExpr */*expression*/) {}

void GarbageCollector::Visit(Class *expression) {
    for (auto& field : expression->GetVariable()) {
        field->Accept(*this);
        delete field;
    }
    for (auto& method : expression->GetMethods()) {
        method->Accept(*this);
        delete method;
    }
}

void GarbageCollector::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
}

void GarbageCollector::Visit(MethodInvocation *expression) {
    expression->callable_expr->Accept(*this);
    delete expression->callable_expr;
    for (auto& arg : expression->arguments->GetExpr()) {
        arg->Accept(*this);
        delete arg;
    }
}

void GarbageCollector::Visit(If *branching) {
    branching->GetStatement()->Accept(*this);
    branching->GetTrueBranch()->Accept(*this);
    if (branching->GetFalseBranch()) {
        branching->GetFalseBranch()->Accept(*this);
    }
    delete branching->GetStatement();
    delete branching->GetTrueBranch();
    delete branching->GetFalseBranch();
}

void GarbageCollector::Visit(While *expression) {
    expression->GetStatement()->Accept(*this);
    expression->GetCycleBody()->Accept(*this);
    delete expression->GetStatement();
    delete expression->GetCycleBody();
}

void GarbageCollector::Visit(MethodDeclaration *expression) {
    if (expression->GetCode()) {
        expression->GetCode()->Accept(*this);
    }
    if (expression->GetFormals()) {
        expression->GetFormals()->Accept(*this);
    }
    delete expression->GetCode();
    delete expression->GetFormals();
    delete expression->GetType();
}

void GarbageCollector::Visit(Println *expression) {
    if (expression->GetExpression()) {
        expression->GetExpression()->Accept(*this);
    }
    delete expression->GetExpression();
}

void GarbageCollector::Visit(Return *expression) {
    if (expression->GetExpression()) {
        expression->GetExpression()->Accept(*this);
    }
    delete expression->GetExpression();
}

void GarbageCollector::Visit(VariableDeclaration *expression) {
    delete expression->GetType();
}

void GarbageCollector::Visit(AssertExpr *expression) {
    if (expression->GetExpression()) {
        expression->GetExpression()->Accept(*this);
    }
    delete expression->GetExpression();
}

void GarbageCollector::Visit(Assignment *assignment) {
    assignment->GetTo()->Accept(*this);
    assignment->GetFrom()->Accept(*this);
    delete assignment->GetTo();
    delete assignment->GetFrom();
}

void GarbageCollector::Visit(Block *expression) {
    expression->GetExecCode()->Accept(*this);
    delete expression->GetExecCode();
}

void GarbageCollector::Visit(ExecCode *expression) {
    for (auto& line : expression->GetProgramLines()) {
        line->Accept(*this);
        delete line;
    }
}

void GarbageCollector::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->GetClasses()) {
        class_decl->Accept(*this);
        delete class_decl;
    }
    delete program->main_class;
    delete program->class_decl_list;
}

void GarbageCollector::Visit(Formals *formals) {
    for (auto& variable : formals->GetVariables()) {
        delete variable;
    }
}
