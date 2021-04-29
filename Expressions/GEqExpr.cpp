#include "GEqExpr.h"

GEqExpr::GEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

GEqExpr::~GEqExpr()
{
    delete p_lhs;
    delete p_rhs;
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
