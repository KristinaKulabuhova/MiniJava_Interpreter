#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(VarTypeStr type, std::string name, int value) :
type_(type), name_(std::move(name)), value_(value) {}

int VariableDeclaration::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

VarTypeStr VariableDeclaration::getType() const {
    return type_;
}

std::string VariableDeclaration::getName() const {
    return name_;
}

int VariableDeclaration::getValue() const {
    return value_;
}
