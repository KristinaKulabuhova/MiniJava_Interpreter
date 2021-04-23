#pragma once

#include "vector"
#include "Visitors/Visitor.h"
#include "Expressions/VarType.h"

class Formals {
  public:
    std::vector<std::pair<VarTypeStr*, std::string>> variables;
    Formals(VarTypeStr* type, std::string name);
    void addVar(VarTypeStr* type, std::string name);
    void Accept(Visitor& visitor);
};
