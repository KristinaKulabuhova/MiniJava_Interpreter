#pragma once

#include "Visitors/Visitor.h"

class BaseExecBlock {
  public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~BaseExecBlock() = default;
};

