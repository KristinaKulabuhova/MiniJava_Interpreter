#pragma once

#include <string>

class SimpleType
{
public:
  SimpleType(int type_id, std::string name);
  ~SimpleType() = default;

public:
  std::string type_name_;
  int type_id;
};