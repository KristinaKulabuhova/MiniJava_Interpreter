#include "Write.h"

Write::Write(BaseExpr *expression) : expression(expression) {}

Write::~Write() {
    delete expression;
}

void Write::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
