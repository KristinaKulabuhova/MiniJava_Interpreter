#include "MulExpr.h"

MulExpr::MulExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

MulExpr::~MulExpr()
{
    delete p_lhs;
    delete p_lhs;
}

void MulExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *MulExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *MulExpr::GetRight() const
{
    return p_rhs;
}