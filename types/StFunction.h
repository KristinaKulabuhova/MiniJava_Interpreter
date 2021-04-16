#pragma once 

#include <types/Symbol.h>
#include "ExecBlocks/MethodDeclaration.h"
#include <memory>

#include <string>
#include <vector>
#include <unordered_map>

class StFunction : public Symbol {
public:
    explicit StFunction(std::shared_ptr<MethodDeclaration> declaration);
    std::string getName() const;
private:
    std::string name_;
    std::shared_ptr<MethodDeclaration> declaration_;
};
