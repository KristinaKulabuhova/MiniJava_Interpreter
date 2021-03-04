#include "VarExpr.h"

VarExpr::VarExpr(std::string name) : name(std::move(name)), index(nullptr) {}

VarExpr::VarExpr(std::string name, BaseExpr *index) : name(std::move(name)), index(index) {}

int VarExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

VarExpr::~VarExpr() {
    delete index;
}
