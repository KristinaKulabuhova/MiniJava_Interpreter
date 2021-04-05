#pragma once 

#include "ScopeLayer.h"

class ScopeLay {
    public:
        explicit ScopeLayerTree(std::shared_ptr<ScopeLay>)

        std::shared_ptr<SymbolLayer> GetRoot() const;
        
    private:  
        std::shared_ptr<ScopeLayer> root_;
};