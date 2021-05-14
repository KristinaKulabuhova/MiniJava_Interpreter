#pragma once

#include "Visitors/Visitor.h"
#include "parser.hh"

class BaseExecBlock
{
public:
  virtual void Accept(Visitor &visitor) = 0;
  virtual ~BaseExecBlock() = default;
  BaseExecBlock(yy::location loc) : location_(loc)
  {
  }

  yy::location GetLoc() const {
    return location_;
  }

public:
  yy::location location_;
};