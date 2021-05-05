#include "StVariable.h"

StVariable::StVariable(const VarTypeStr& type) : type_(type) {}

VarTypeStr StVariable::GetType() const {
    return type_;
}