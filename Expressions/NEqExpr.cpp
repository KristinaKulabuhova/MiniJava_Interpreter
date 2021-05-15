#include "NEqExpr.h"

NEqExpr::NEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs; 
    p_rhs_ = p_rhs;
}

void NEqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *NEqExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *NEqExpr::GetRight() const
{
    return p_rhs_;
}