#pragma once

#include "BaseSymbol.h"
#include "StArgument.h"

#include <vector>
#include "ExecBlocks/MethodDeclaration.h"

class StFunction: public BaseSymbol {
 public:
  std::vector<StArgument> arguments;
  VarTypeStr return_type;
  explicit StFunction(MethodDeclaration* function);
};
