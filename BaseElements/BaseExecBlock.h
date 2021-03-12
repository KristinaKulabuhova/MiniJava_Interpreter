#ifndef PARSEREXAMPLE_BASEEXECBLOCK_H
#define PARSEREXAMPLE_BASEEXECBLOCK_H

#include "Visitors/Visitor.h"

class BaseExecBlock {
  public:
    virtual int Accept(Visitor& visitor) = 0;
    virtual ~BaseExecBlock() = default;
};

#endif //PARSEREXAMPLE_BASEEXECBLOCK_H
