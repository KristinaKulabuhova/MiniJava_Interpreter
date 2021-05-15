#include "AddExpr.h"

AddExpr::AddExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void AddExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *AddExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *AddExpr::GetRight() const
{
    return p_rhs_;
}
