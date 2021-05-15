#include "AndExpr.h"

AndExpr::AndExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void AndExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *AndExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *AndExpr::GetRight() const
{
    return p_rhs_;
}