#include "Println.h"

Println::Println(BaseExpr *expression_, yy::location loc) : BaseExecBlock(loc)
{ 
    expression = expression_;
}

void Println::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

  BaseExpr* Println::GetExpression() const {
      return expression;
  }
