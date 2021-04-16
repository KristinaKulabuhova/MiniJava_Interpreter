#pragma once 

#include "ScopeLayer.h"

class ScopeLayerTree {
    public:
        explicit ScopeLayerTree(std::shared_ptr<ScopeLayer> );
        std::shared_ptr<ScopeLayer> getRoot() const;
    private:  
        std::shared_ptr<ScopeLayer> root_;
};