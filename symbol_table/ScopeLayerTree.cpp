
#include <symbol_table/ScopeLayerTree.h>

SymbolTree::SymbolTree(std::shared_ptr<SymbolLayer> root) : root_(root) {
}

std::shared_ptr<SymbolLayer> SymbolTree::GetRoot() const {
    return root_;
}
