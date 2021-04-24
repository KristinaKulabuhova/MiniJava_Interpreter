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

  void addDecl(const std::variant<MethodDeclaration *, VariableDeclaration *> &declaration);

public:
  std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> declarations;
};
