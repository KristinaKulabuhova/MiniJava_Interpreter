#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression) : expression(expression) {}

BaseExpr* AssertExpr::GetExpression() const {
    return expression;
  }

void AssertExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
