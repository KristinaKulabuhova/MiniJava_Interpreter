#pragma once
#include <string>


class SimpleType {
  public:
    SimpleType(int type_id, std::string name) : type_name_(name), type_id(type_id) {} 
    std::string type_name_;
    int type_id;
};