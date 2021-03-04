#include "LEqExpr.h"

LEqExpr::LEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

LEqExpr::~LEqExpr() {
    delete p_lhs;
    delete p_rhs;
}

int LEqExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
