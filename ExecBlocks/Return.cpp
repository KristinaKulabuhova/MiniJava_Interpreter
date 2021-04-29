#include "Return.h"

Return::Return(BaseExpr *expression) : expression(expression) {}

void Return::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

 BaseExpr* Return::GetExpression() const {
     return expression;
 }