#pragma once

#include "BaseSymbol.h"

#include <string>
class StArgument : public BaseSymbol {
 public:
  explicit StArgument(std::string /*argument*/) {}
  std::string type = "int";
};
