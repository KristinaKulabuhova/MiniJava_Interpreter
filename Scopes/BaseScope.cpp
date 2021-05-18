#include "BaseScope.h"

#include <iostream>

bool BaseScope::AddElement(const std::string& name, BaseSymbol *symbol) {

    if (elements.find(name) != elements.end()) {
        return false;
    }
    elements[name] = symbol;
    return true;
}

BaseSymbol *BaseScope::GetElement(const std::string &name) {
    if (elements.find(name) == elements.end()) {
        if (!parent_) {
            return nullptr;
        } else {
            return parent_->GetElement(name);
        }
    }
    return elements[name];
}

BaseScope *BaseScope::CreateChild() {
    children_.emplace_back(new BaseScope);
    children_.back()->parent_ = this;
    return children_.back();
}

BaseScope *BaseScope::GetChild(size_t index) {
    if (index < children_.size()) {
        return children_[index];
    }
    return nullptr;
}

BaseScope *BaseScope::GetParent() const {
    return parent_;
}
