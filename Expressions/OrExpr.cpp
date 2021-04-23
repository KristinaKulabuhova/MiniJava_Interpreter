#include "OrExpr.h"

OrExpr::OrExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

OrExpr::~OrExpr() {
    delete p_lhs;
    delete p_rhs;
}

void OrExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
