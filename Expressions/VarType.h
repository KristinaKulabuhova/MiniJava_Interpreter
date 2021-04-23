#pragma once

#include "Expressions/SimpleType.h"

enum VarType {
  int_t,
  bool_t,
  void_t,
  custom_t
};


class VarTypeStr {
  public:
    explicit VarTypeStr(SimpleType* simple_type, bool array = false) : type(simple_type->type_id), array(array), name_(simple_type->type_name_) {}
    int type;
    bool array{false};
    std::string name_;
};
