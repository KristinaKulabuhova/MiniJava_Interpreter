#pragma once

#include "Symbol.h"
#include "objects/Object.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>


class ScopeLayer : public std::enable_shared_from_this<ScopeLayer> {

  public:
    explicit ScopeLayer(std::shared_ptr<ScopeLayer> parent);
    ScopeLayer() = default;

    void DeclareVariable(Symbol symbol);
    void Put(Symbol symbol, std::shared_ptr<Object> value);
    std::shared_ptr<Object> Get(Symbol symbol);
    bool Has(Symbol symbol);

    std::shared_ptr<SymbolLayer> GetParent() const;
    std::shared_ptr<SymbolLayer> GetChild(size_t index);

    void AddChild(std::shared_ptr<SymbolLayer> child);

  private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::unordered_map<std::string, size_t> symbol_offset_;
    std::vector<Symbol> symbols_; // table of symbols
    std::string name_;
    std::weak_ptr<SymbolLayer> parent_;
    std::vector<std::shared_ptr<SymbolLayer>> children_;
};