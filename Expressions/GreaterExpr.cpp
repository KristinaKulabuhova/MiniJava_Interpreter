#include "GreaterExpr.h"

GreaterExpr::GreaterExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

GreaterExpr::~GreaterExpr()
{
    delete p_lhs;
    delete p_rhs;
}

void GreaterExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *GreaterExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *GreaterExpr::GetRight() const
{
    return p_rhs;
}