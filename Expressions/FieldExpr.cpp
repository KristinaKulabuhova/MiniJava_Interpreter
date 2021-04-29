#include "FieldExpr.h"

void FieldExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

FieldExpr::FieldExpr(std::string name) : name_(std::move(name)) {}

std::string FieldExpr::GetName() const {
    return name_;
}
