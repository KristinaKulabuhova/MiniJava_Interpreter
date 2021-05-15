#include "Println.h"

Println::Println(BaseExpr *expression, yy::location loc) : BaseExecBlock(loc)
{ 
    expression_ = expression;
}

void Println::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

  BaseExpr* Println::GetExpression() const {
      return expression_;
  }
