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

Formals::~Formals() {
    for (auto& arg : variables) {
        delete arg;
    }
}

std::vector<VarTypeStr *> Formals::GetVariables() const {
    return variables;
}
