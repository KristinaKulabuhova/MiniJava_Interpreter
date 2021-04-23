#pragma once

#include "Visitors/Visitor.h"

class BaseExpr {
  public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~BaseExpr() = default;
};


