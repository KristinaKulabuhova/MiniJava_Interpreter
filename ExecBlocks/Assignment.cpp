#include "Assignment.h"

Assignment::Assignment(Lvalue* var, BaseExpr *expression) : var(var), expression(expression) {}

int Assignment::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Assignment::~Assignment() {
    delete expression;
}
