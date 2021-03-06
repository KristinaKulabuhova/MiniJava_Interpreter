#include "LEqExpr.h"

LEqExpr::LEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc)
{
    p_lhs_ = p_lhs;
    p_rhs_ = p_rhs;
}

void LEqExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *LEqExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *LEqExpr::GetRight() const
{
    return p_rhs_;
}
