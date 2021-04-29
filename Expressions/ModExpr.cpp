#include "ModExpr.h"

ModExpr::ModExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

void ModExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *ModExpr::GetLeft() const
{
    return p_lhs;
}

BaseExpr *ModExpr::GetRight() const
{
    return p_rhs;
}