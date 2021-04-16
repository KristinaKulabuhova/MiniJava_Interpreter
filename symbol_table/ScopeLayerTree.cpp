#include <symbol_table/ScopeLayerTree.h>

#include <utility>

ScopeLayerTree::ScopeLayerTree(std::shared_ptr<ScopeLayer>  root) : root_(std::move(root)) {}

std::shared_ptr<ScopeLayer> ScopeLayerTree::getRoot() const {
    return root_;
}
