#pragma once

#include "unordered_map"
#include "vector"
#include "symbols/BaseSymbol.h"

class BaseScope {
  public:
    bool AddElement(const std::string& name, BaseSymbol* symbol);
    BaseSymbol* GetElement(const std::string& name);
    BaseScope* CreateChild();

  private:
    std::unordered_map<std::string, BaseSymbol*> elements;
    std::vector<BaseScope*> children_;
    BaseScope* parent_;
};
