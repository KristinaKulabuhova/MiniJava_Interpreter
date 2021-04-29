#include "LEqExpr.h"

LEqExpr::LEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

void LEqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *LEqExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *LEqExpr::GetRight() const
{
    return p_rhs;
}
