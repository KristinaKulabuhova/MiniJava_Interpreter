#pragma once

#include "Visitors/Visitor.h"
#include "ExecBlocks/MethodDeclaration.h"
#include <vector>
#include <variant>

class DeclarationList {
  public:
    std::vector<std::variant<MethodDeclaration*, VariableDeclaration*>> declarations;
    void addDecl(const std::variant<MethodDeclaration*, VariableDeclaration*>& declaration);
};

