#include "GeqExpr.h"

GeqExpr::GeqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

GeqExpr::~GeqExpr() {
    delete p_lhs;
    delete p_rhs;
}

var_t GeqExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
