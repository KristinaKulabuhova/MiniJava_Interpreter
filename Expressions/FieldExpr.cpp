#include "FieldExpr.h"

int FieldExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

FieldExpr::FieldExpr(std::string name) : name(std::move(name)) {}
