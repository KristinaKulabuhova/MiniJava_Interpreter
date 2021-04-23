#pragma once

#include <string>

class BaseSymbol {
 public:
  std::string name;
  virtual ~BaseSymbol() = default;
};
