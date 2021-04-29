#include "AndExpr.h"

AndExpr::AndExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

AndExpr::~AndExpr()
{
    delete p_lhs;
    delete p_rhs;
}

void AndExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *AndExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *AndExpr::GetRight() const
{
    return p_rhs;
}