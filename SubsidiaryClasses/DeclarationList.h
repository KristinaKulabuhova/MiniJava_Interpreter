#pragma once

#include "Visitors/Visitor.h"
#include "ExecBlocks/MethodDeclaration.h"
#include <vector>
#include <variant>

class DeclarationList
{
public:
  DeclarationList() = default;
  ~DeclarationList() = default;

  void addDecl(BaseExecBlock *declaration);

  std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> GetDeclarations() const;

private:
  std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> declarations;
};
