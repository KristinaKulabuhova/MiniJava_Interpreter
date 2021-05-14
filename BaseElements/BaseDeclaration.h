#pragma once

#include "Visitors/Visitor.h"
#include "parser.hh"

class BaseDeclaration
{
public:
  virtual void Accept(Visitor &visitor) = 0;
  virtual ~BaseDeclaration() = default;
  BaseDeclaration(yy::location loc) : location_(loc)
  {
  }

  yy::location GetLoc() const {
    return location_;
  }

public:
  yy::location location_;
};