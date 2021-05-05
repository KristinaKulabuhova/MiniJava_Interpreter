#include "Formals.h"

Formals::Formals(VarTypeStr *type)
{
    variables.emplace_back(type);
}

void Formals::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

void Formals::addVar(VarTypeStr *type) {
    variables.emplace_back(type);
}

std::vector<VarTypeStr *> Formals::GetVariables() const {
    return variables;
}
