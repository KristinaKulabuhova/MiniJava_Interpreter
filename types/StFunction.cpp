#include "StFunction.h"


StFunction::StFunction(std::shared_ptr <MethodDeclaration> declaration) :
name_(declaration->getName()), declaration_(std::move(declaration)) {}

std::string StFunction::getName() const {
    return name_;
}
