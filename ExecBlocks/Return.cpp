#include "Return.h"

Return::Return(BaseExpr *expression, yy::location loc) : BaseExecBlock(loc)
{
    expression_ = expression;
}

void Return::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

 BaseExpr* Return::GetExpression() const {
     return expression_;
 }