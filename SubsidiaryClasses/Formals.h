#pragma once

#include "vector"
#include "Visitors/Visitor.h"
#include "Expressions/VarType.h"

class Formals
{
public:
  Formals(VarTypeStr *type, std::string name);
  ~Formals() = default;

  void addVar(VarTypeStr *type, std::string name);
  void Accept(Visitor &visitor);

public:
  std::vector<std::pair<VarTypeStr *, std::string>> variables;
};
