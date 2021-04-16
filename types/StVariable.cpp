#include "StVariable.h"

#include <utility>

StVariable::StVariable(std::shared_ptr<VariableDeclaration>  declaration) :
name_(declaration->getName()), declaration_(std::move(declaration)) {}

std::string StVariable::getName() const {
    return name_;
}
