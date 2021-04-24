#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression) : expression(expression) {}

AssertExpr::~AssertExpr()
{
    delete expression;
}

void AssertExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
