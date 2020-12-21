#include "SubtractExpr.h"

SubtractExpr::~SubtractExpr() {
    delete p_rhs;
    delete p_lhs;
}

var_t SubtractExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

SubtractExpr::SubtractExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}
