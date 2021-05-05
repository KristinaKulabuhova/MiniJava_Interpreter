#pragma once

#include <string>

class SimpleType
{
public:
  SimpleType(int type_id, std::string name);
  ~SimpleType() = default;

  std::string GetName() const;
  int GetId() const;

private:
  std::string type_name_;
  int type_id;
};