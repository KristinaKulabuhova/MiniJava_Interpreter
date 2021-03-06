#include "EqExpr.h"

EqExpr::EqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void EqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *EqExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *EqExpr::GetRight() const
{
    return p_rhs_;
}
