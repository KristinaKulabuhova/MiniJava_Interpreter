#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(VarTypeStr *type, std::string name, int value) : type_(type), name_(std::move(name)), value_(value) {}

VarTypeStr *VariableDeclaration::GetType() const
{
    return type_;
}

std::string VariableDeclaration::GetName() const
{
    return name_;
}

int VariableDeclaration::GetValue() const
{
    return value_;
}

void VariableDeclaration::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}