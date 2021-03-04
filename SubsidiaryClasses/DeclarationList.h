#ifndef PARSEREXAMPLE_DECLARATIONLIST_H
#define PARSEREXAMPLE_DECLARATIONLIST_H

#include "Visitors/Visitor.h"
#include "MainElements/MethodDeclaration.h"
#include <vector>
#include <variant>

class DeclarationList {
  public:
    std::vector<std::variant<MethodDeclaration*, VariableDeclaration*>> declarations;
    void addDecl(const std::variant<MethodDeclaration*, VariableDeclaration*>& declaration);
};

#endif