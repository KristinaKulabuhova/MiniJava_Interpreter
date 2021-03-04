#include "Formals.h"

Formals::Formals(VarType type, std::string name) {
    variables.emplace_back(type, std::move(name));
}

void Formals::addVar(VarType type, std::string name) {
    variables.emplace_back(type, std::move(name));
}
