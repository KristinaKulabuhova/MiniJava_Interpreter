#pragma once

#include "BaseSymbol.h"

#include "Expressions/VarType.h"

class StVariable : public BaseSymbol
{
public:
  explicit StVariable(const VarTypeStr &type);
  ~StVariable() = default;

  VarTypeStr GetType() const;

private:
  VarTypeStr type_;
};