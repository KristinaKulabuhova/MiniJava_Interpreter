#include "AndExpr.h"

AndExpr::AndExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

AndExpr::~AndExpr() {
    delete p_lhs;
    delete p_rhs;
}

int AndExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}