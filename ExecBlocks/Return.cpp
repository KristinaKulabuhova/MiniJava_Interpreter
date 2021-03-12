#include "Return.h"

Return::Return(BaseExpr *expression) : expression(expression) {}

int Return::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Return::~Return() {
    delete expression;
}
