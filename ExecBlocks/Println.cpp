#include "Println.h"

Println::Println(BaseExpr *expression) : expression(expression) {}

void Println::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

Println::~Println() {
    delete expression;
}
