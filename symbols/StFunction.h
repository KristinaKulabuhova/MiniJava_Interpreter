#pragma once

#include "BaseSymbol.h"
#include "StArgument.h"

#include <vector>
#include "ExecBlocks/MethodDeclaration.h"

class StFunction: public BaseSymbol {
 public:
  std::vector<StArgument> arguments;
  std::string return_type;
  explicit StFunction(MethodDeclaration* function);
};
