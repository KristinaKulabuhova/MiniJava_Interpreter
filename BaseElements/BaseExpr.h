#ifndef PARSEREXAMPLE_BASEEXPR_H
#define PARSEREXAMPLE_BASEEXPR_H

#include "Visitors/Visitor.h"

class BaseExpr {
  public:
    virtual var_t Accept(Visitor& visitor) = 0;
    virtual ~BaseExpr() = default;
};

#endif //PARSEREXAMPLE_BASEEXPR_H
