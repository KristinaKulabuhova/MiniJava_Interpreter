#include "FieldExpr.h"

FieldExpr::FieldExpr(std::string name) : name(std::move(name)), index(nullptr) {}

FieldExpr::FieldExpr(std::string name, BaseExpr *index) : name(std::move(name)), index(index) {}

int FieldExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

FieldExpr::~FieldExpr() {
    delete index;
}
