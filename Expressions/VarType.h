#pragma once

#include "Expressions/SimpleType.h"

enum VarType
{
  int_t,
  bool_t,
  void_t,
  custom_t
};

class VarTypeStr
{
public:
  explicit VarTypeStr(SimpleType *simple_type, bool array = false);
  VarTypeStr(const VarTypeStr&) = default;
  ~VarTypeStr() = default;
  
  std::string& GetName();
  bool GetArray() const;
  int GetType() const;

private:
  int type_;
  bool array_{false};
  std::string name_;
};
