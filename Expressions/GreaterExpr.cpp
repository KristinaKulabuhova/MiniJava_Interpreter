#include "GreaterExpr.h"

GreaterExpr::GreaterExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void GreaterExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *GreaterExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *GreaterExpr::GetRight() const
{
    return p_rhs_;
}