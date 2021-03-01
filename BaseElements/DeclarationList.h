#ifndef PARSEREXAMPLE_DECLARATIONLIST_H
#define PARSEREXAMPLE_DECLARATIONLIST_H

#include "Visitors/Visitor.h"
#include <variant>

class DeclarationList {
  public:
    std::vector<std::variant<Method*, Variable*>> declarations;
}