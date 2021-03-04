#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(VarType type, std::string name, int value) :
type_(type), name_(std::move(name)), value_(value) {}

void VariableDeclaration::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
