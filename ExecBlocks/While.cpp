#include "While.h"

While::While(BaseExpr *statement, BaseExecBlock *cycle_body) : statement(statement), cycle_body(cycle_body) {}

While::~While()
{
    delete statement;
    delete cycle_body;
}

void While::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr* While::GetStatement() const {
    return statement;
}

BaseExecBlock* While::GetCycleBody() const {
    return cycle_body;
}