#pragma once

#include <string>

class BaseSymbol
{
public:
  BaseSymbol() = default;
  virtual ~BaseSymbol() = default;

public:
  std::string name;
};
