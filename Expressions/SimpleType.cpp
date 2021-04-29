#include "SimpleType.h"

SimpleType::SimpleType(int id, std::string name) : type_name_(name), type_id(id) {}

std::string SimpleType::GetName() const {
    return type_name_;
}

int SimpleType::GetId() const {
    return type_id;
}