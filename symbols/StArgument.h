#pragma once

#include "BaseSymbol.h"

#include "Expressions/VarType.h"

#include <string>
class StArgument : public BaseSymbol {
 public:
  explicit StArgument(const VarTypeStr& type);

  VarTypeStr type;
};
