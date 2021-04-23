#include "SubtractExpr.h"

SubtractExpr::~SubtractExpr() {
    delete p_rhs;
    delete p_lhs;
}

void SubtractExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

SubtractExpr::SubtractExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}
