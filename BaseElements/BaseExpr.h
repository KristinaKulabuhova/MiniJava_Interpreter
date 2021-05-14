#pragma once

#include "Visitors/Visitor.h"
#include "parser.hh"

class BaseExpr
{
public:
  virtual void Accept(Visitor &visitor) = 0;
  virtual ~BaseExpr() = default;
  BaseExpr(yy::location loc) : location_(loc)
  {
  }

  yy::location GetLoc() const {
    return location_;
  }

public:
  yy::location location_;
};