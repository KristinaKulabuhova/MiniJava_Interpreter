#include "AddExpr.h"

AddExpr::~AddExpr() {
    delete p_lhs;
    delete p_rhs;
}

int AddExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

AddExpr::AddExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}
