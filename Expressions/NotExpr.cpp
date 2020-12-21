#include "NotExpr.h"

NotExpr::NotExpr(BaseExpr *p_expr) : p_expr(p_expr) {}

NotExpr::~NotExpr() {
    delete p_expr;
}

var_t NotExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
