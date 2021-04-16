#include "StClass.h"

StClass::StClass(std::shared_ptr<Class> declaration) :
name_(declaration->name_), declaration_(std::move(declaration)) {}

std::string StClass::getName() const {
    return name_;
}
