#include "If.h"

If::If(BaseExpr *statement, BaseExecBlock *true_branch, BaseExecBlock *false_branch) : statement(statement), true_branch(true_branch), false_branch(false_branch) {}

If::~If()
{
    delete statement;
    delete true_branch;
    delete false_branch;
}

void If::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}