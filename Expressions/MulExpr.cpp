#include "MulExpr.h"

MulExpr::MulExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void MulExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *MulExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *MulExpr::GetRight() const
{
    return p_rhs_;
}