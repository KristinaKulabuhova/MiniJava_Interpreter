#include "ModExpr.h"

ModExpr::ModExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

ModExpr::~ModExpr()
{
    delete p_lhs;
    delete p_rhs;
}

void ModExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}