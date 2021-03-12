#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression) : expression(expression) {}

int AssertExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

AssertExpr::~AssertExpr() {
    delete expression;
}
