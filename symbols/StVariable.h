#pragma once

#include "BaseSymbol.h"


class StVariable : public BaseSymbol {
 public:
  explicit StVariable(std::string name);
  std::string type = "int";
};