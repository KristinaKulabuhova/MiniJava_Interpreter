#include "ModExpr.h"

ModExpr::ModExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc) : BaseExpr(loc) 
{
    p_lhs_ = p_lhs; 
    p_rhs_ = p_rhs;
}

void ModExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *ModExpr::GetLeft() const
{
    return p_lhs_;
}

BaseExpr *ModExpr::GetRight() const
{
    return p_rhs_;
}