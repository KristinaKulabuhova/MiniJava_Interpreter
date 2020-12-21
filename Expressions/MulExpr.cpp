#include "MulExpr.h"

MulExpr::~MulExpr() {
    delete p_lhs;
    delete p_lhs;
}

var_t MulExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

MulExpr::MulExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}
