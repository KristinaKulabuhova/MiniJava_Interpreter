#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression, yy::location loc) : BaseExecBlock(loc) 
{
  expression = expression;
}

BaseExpr* AssertExpr::GetExpression() const {
    return expression;
  }

void AssertExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
