#include "GEqExpr.h"

GEqExpr::GEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

GEqExpr::~GEqExpr() {
    delete p_lhs;
    delete p_rhs;
}

int GEqExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
