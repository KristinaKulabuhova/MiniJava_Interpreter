#include "ScopeLayer.h"

#include "objects/UninitObject.h"

#include <iostream>

ScopeLayer::ScopeLayer(std::shared_ptr<ScopeLayer> parent): parent_(parent) {
    parent_->AddChild(shared_from_this(this));
}

ScopeLayer::ScopeLayer(): parent_(nullptr) {}

void ScopeLayer::DeclareVariable(Symbol symbol) {
    if (values_.find(symbol) != values_.end()) {
        throw std::runtime_error("Variable has declared");
    }

    values_[symbol] = std::make_shared<UninitObject>();
}

void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {

    std::shared_ptr<SymbolLayer> current_layer = shared_from_this(this);

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }
    if (current_layer->Has(symbol)) {
        current_layer->values_.find(symbol)->second = value;
    } else {
        throw std::runtime_error("Variable not declared");
    }
}

bool ScopeLayer::Has(Symbol symbol) {
    return values_.find(symbol) != values_.end();
}


std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
    std::shared_ptr<SymbolLayer> current_layer = shared_from_this(this);

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }
    if (current_layer->Has(symbol)) {
        return current_layer->values_.find(symbol)->second;
    } else {
        throw std::runtime_error("Variable not declared");
    }
}

std::shared_ptr<SymbolLayer> ScopeLayer::GetChild(size_t index) {
    std::cout << "Children of scope: " << children_.size() << std::endl;
    return children_[index];
}

void ScopeLayer::AddChild(std::shared_ptr<SymbolLayer> child) {
    children_.push_back(child);
}

std::shared_ptr<SymbolLayer> ScopeLayer::GetParent() const {
    return parent_;
}