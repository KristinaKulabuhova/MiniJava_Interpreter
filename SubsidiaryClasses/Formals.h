#pragma once

#include "vector"
#include "Visitors/Visitor.h"
#include "Expressions/VarType.h"

class Formals
{
public:
  explicit Formals(VarTypeStr *type);
  ~Formals();

  void addVar(VarTypeStr *type);
  void Accept(Visitor &visitor);

public:
  std::vector<VarTypeStr *> variables;
};
