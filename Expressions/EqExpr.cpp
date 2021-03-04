#include "EqExpr.h"

EqExpr::EqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

EqExpr::~EqExpr() {
    delete p_lhs;
    delete p_rhs;
}

int EqExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
