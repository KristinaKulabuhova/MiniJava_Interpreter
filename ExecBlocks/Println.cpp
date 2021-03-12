#include "Println.h"

Println::Println(BaseExpr *expression) : expression(expression) {}

int Println::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Println::~Println() {
    delete expression;
}
