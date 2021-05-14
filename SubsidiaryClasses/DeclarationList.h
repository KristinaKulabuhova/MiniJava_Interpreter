#pragma once

#include "Visitors/Visitor.h"
#include "ExecBlocks/MethodDeclaration.h"
#include <vector>
#include <variant>

class DeclarationList
{
public:
  DeclarationList(yy::location loc);
  ~DeclarationList() = default;

  void addDecl(BaseExecBlock *declaration);

  std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> GetDeclarations() const;

private:
  yy::location location_;
  std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> declarations;
};
