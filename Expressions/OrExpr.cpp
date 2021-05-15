#include "OrExpr.h"

OrExpr::OrExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc) 
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void OrExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *OrExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *OrExpr::GetRight() const
{
    return p_rhs_;
}