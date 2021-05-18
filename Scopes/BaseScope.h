#pragma once

#include "unordered_map"
#include "vector"
#include "symbols/BaseSymbol.h"
#include "Visitors/Visitor.h"

class BaseScope {
  public:
    bool AddElement(const std::string& name, BaseSymbol* symbol);
    BaseSymbol* GetElement(const std::string& name);
    BaseScope* CreateChild();
    BaseScope* GetChild(size_t index);
    BaseScope* GetParent() const;

  private:
    std::unordered_map<std::string, BaseSymbol*> elements;
    std::vector<BaseScope*> children_;
    BaseScope* parent_;
};
