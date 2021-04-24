#include "DivExpr.h"

DivExpr::DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

DivExpr::~DivExpr()
{
    delete p_lhs;
    delete p_rhs;
}

void DivExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}