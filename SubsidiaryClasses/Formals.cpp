#include "Formals.h"

Formals::Formals(VarTypeStr type, std::string name) {
    variables.emplace_back(type, std::move(name));
}

void Formals::addVar(VarTypeStr type, std::string name) {
    variables.emplace_back(type, std::move(name));
}
