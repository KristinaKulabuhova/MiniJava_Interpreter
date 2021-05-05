#pragma once

#include "vector"
#include "Visitors/Visitor.h"
#include "Expressions/VarType.h"

class Formals
{
public:
  explicit Formals(VarTypeStr *type);
  ~Formals() = default;

  void addVar(VarTypeStr *type);
  void Accept(Visitor &visitor);

  std::vector<VarTypeStr *> GetVariables() const;

private:
  std::vector<VarTypeStr *> variables;
};
