#include "NEqExpr.h"

NEqExpr::NEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

void NEqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *NEqExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *NEqExpr::GetRight() const
{
    return p_rhs;
}