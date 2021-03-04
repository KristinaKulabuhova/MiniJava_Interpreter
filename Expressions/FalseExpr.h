#ifndef PASCAL_FALSEEXPR_H
#define PASCAL_FALSEEXPR_H

#include "BaseElements/BaseExpr.h"

class FalseExpr : BaseExpr {
  public:
    FalseExpr() = default;
    ~FalseExpr() override = default;
    int Accept(Visitor& visitor) override;
};


#endif //PASCAL_FALSEEXPR_H
