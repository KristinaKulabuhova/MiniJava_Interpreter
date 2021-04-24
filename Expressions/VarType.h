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
  ~VarTypeStr() = default;
  VarTypeStr(const VarTypeStr&) = default;

public:
  int type;
  bool array{false};
  std::string name_;
};
