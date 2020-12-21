#include "LeqExpr.h"

LeqExpr::LeqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

LeqExpr::~LeqExpr() {
    delete p_lhs;
    delete p_rhs;
}

var_t LeqExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
