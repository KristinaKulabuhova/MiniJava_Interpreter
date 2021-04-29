#include "EqExpr.h"

EqExpr::EqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

void EqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *EqExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *EqExpr::GetRight() const
{
    return p_rhs;
}
