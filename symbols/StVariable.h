#pragma once

#include "BaseSymbol.h"

#include "Expressions/VarType.h"


class StVariable : public BaseSymbol {
 public:
  explicit StVariable(const VarTypeStr& type);
  VarTypeStr type_;
};