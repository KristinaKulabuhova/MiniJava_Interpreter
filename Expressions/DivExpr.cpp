#include "DivExpr.h"

DivExpr::DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs = p_lhs;
    p_rhs = p_rhs;
}

void DivExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *DivExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *DivExpr::GetRight() const
{
    return p_rhs;
}