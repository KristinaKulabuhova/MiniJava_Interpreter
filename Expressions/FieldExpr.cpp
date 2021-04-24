#include "FieldExpr.h"

void FieldExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

FieldExpr::FieldExpr(std::string name) : name(std::move(name)) {}
