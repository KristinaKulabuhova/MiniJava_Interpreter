#include "SubtractExpr.h"

SubtractExpr::SubtractExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{ 
    p_lhs = p_lhs;
    p_rhs = p_rhs;
}

void SubtractExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *SubtractExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *SubtractExpr::GetRight() const
{
    return p_rhs;
}