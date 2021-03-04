#include "GreaterExpr.h"

GreaterExpr::GreaterExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

GreaterExpr::~GreaterExpr() {
    delete p_lhs;
    delete p_rhs;
}

int GreaterExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
