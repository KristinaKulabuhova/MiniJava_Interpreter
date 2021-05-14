#include "GEqExpr.h"

GEqExpr::GEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs = p_lhs;
    p_rhs = p_rhs;
}

void GEqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *GEqExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *GEqExpr::GetRight() const
{
    return p_rhs;
}
