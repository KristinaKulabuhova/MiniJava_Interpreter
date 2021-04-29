#include "VarType.h"

VarTypeStr::VarTypeStr(SimpleType *simple_type, bool array) : type_(simple_type->GetId()), array_(array), name_(simple_type->GetName()) {}

std::string VarTypeStr::GetName() const {
    return name_;
}

 bool VarTypeStr::GetArray() const {
     return array_;
 }

int VarTypeStr::GetType() const {
    return type_;
}