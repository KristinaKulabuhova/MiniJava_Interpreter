#include "LessExpr.h"

LessExpr::LessExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

LessExpr::~LessExpr()
{
    delete p_lhs;
    delete p_rhs;
}

void LessExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
