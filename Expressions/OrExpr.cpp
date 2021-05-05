#include "OrExpr.h"

OrExpr::OrExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

void OrExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *OrExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *OrExpr::GetRight() const
{
    return p_rhs;
}