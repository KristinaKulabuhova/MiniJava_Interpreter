#include "DivExpr.h"

DivExpr::DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void DivExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *DivExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *DivExpr::GetRight() const
{
    return p_rhs_;
}