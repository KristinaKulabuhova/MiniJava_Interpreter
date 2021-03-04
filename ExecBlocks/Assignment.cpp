#include "Assignment.h"

Assignment::Assignment(Lvalue* var, BaseExpr *expression) : var(var), expression(expression) {}

void Assignment::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

Assignment::~Assignment() {
    delete expression;
}
