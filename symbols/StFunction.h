#pragma once

#include "BaseSymbol.h"
#include "StArgument.h"

#include <vector>
#include "ExecBlocks/MethodDeclaration.h"

class StFunction : public BaseSymbol
{
public:
  explicit StFunction(MethodDeclaration *function);

private:
  VarTypeStr return_type_;
  std::vector<StArgument> arguments_;
};
