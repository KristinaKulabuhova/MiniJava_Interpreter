#include "Println.h"

Println::Println(BaseExpr *expression) : expression(expression) {}

Println::~Println()
{
    delete expression;
}

void Println::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}