#include "ScopeLayer.h"

#include <iostream>
#include <utility>

ScopeLayer::ScopeLayer(std::weak_ptr<ScopeLayer> parent, std::string name) :
name_(std::move(name)), parent_(std::move(parent)) {
    parent_.lock()->AddChild(std::shared_ptr<ScopeLayer>(this));
}

//void ScopeLayer::DeclareVariable(std::string name) {
//    if (symbol_table_.find(name) != symbol_table_.end()) {
//        throw std::runtime_error("Variable has declared");
//    }
//
//    symbol_table_[name] = std::make_shared<UninitObject>();
//}

//void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {
//
//    std::shared_ptr<SymbolLayer> current_layer = shared_from_this(this);
//
//    while (!current_layer->Has(symbol) && current_layer->parent_,lock() != nullptr) {
//        current_layer = current_layer->parent_.lock();
//    }
//    if (current_layer->Has(symbol)) {
//        current_layer->values_.find(symbol)->second = value;
//    } else {
//        throw std::runtime_error("Variable not declared");
//    }
//}

bool ScopeLayer::Has(const std::string& name) {
    return symbol_table_.find(name) != symbol_table_.end();
}


std::shared_ptr<Symbol> ScopeLayer::Get(const std::string& name) {
    std::shared_ptr<ScopeLayer> current_layer(this);

    while (!current_layer->Has(name) && current_layer->getParent() != nullptr) {
        current_layer = current_layer->parent_.lock();
    }
    if (current_layer->Has(name)) {
        return current_layer->symbol_table_.find(name)->second;
    } else {
        throw std::runtime_error("Variable not declared");
    }
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetChild(size_t index) {
    std::cout << "Children of scope: " << children_.size() << std::endl;
    return children_[index];
}

void ScopeLayer::AddChild(const std::shared_ptr<ScopeLayer>& child) {
    children_.push_back(child);
}

std::shared_ptr<ScopeLayer> ScopeLayer::getParent() const {
    return parent_.lock();
}

void ScopeLayer::Put(const std::string& name, std::shared_ptr<Symbol> value) {
    symbol_table_[name] = std::move(value);
}
