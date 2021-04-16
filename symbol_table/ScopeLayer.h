#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "types/Symbol.h"


class ScopeLayer : public std::enable_shared_from_this<ScopeLayer> {
    
 public:
    ScopeLayer() = default;

    ScopeLayer(std::weak_ptr<ScopeLayer> parent, std::string name);

//    void DeclareVariable(std::string name);
    void Put(const std::string& name, std::shared_ptr<Symbol> value);
    std::shared_ptr<Symbol> Get(const std::string& name);
    bool Has(const std::string& name);

    std::shared_ptr<ScopeLayer> getParent() const;
    std::shared_ptr<ScopeLayer> GetChild(size_t index);

    void AddChild(const std::shared_ptr<ScopeLayer>& child);

 private:
    std::unordered_map<std::string, std::shared_ptr<Symbol>> symbol_table_;
    std::string name_;
    std::weak_ptr<ScopeLayer> parent_;
    std::vector<std::shared_ptr<ScopeLayer>> children_;
};