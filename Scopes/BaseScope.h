#pragma once

#include "unordered_map"
#include "vector"
#include "symbols/BaseSymbol.h"

class BaseScope {
  public:
    std::unordered_map<std::string, BaseSymbol*> elements;
    std::vector<BaseScope*> children_;
    BaseScope* parent_;
};
