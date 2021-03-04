#include "AssertExpr.h"

AssertExpr::AssertExpr(BaseExpr *expression) : expression(expression) {}

void AssertExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

AssertExpr::~AssertExpr() {
    delete expression;
}
