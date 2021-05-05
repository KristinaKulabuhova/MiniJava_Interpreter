#pragma once

#include <string>

class BaseSymbol
{
public:
  BaseSymbol() = default;
  virtual ~BaseSymbol() = default;

  std::string GetName() const;

private:
  std::string name;
};
