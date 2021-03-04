#include "DivExpr.h"

DivExpr::~DivExpr() {
    delete p_lhs;
    delete p_rhs;
}

int DivExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

DivExpr::DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}
