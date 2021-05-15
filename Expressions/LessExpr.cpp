#include "LessExpr.h"

LessExpr::LessExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void LessExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *LessExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *LessExpr::GetRight() const
{
    return p_rhs_;
}