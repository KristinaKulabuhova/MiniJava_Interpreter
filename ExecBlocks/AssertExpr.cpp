#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression, yy::location loc) : BaseExecBlock(loc) 
{
  expression_ = expression;
}

BaseExpr* AssertExpr::GetExpression() const {
    return expression_;
  }

void AssertExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
