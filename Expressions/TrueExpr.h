#ifndef PASCAL_TRUEEXPR_H
#define PASCAL_TRUEEXPR_H

#include "BaseElements/BaseExpr.h"

class TrueExpr : public BaseExpr{
  public:
    TrueExpr() = default;
    ~TrueExpr() override = default;
    int Accept(Visitor& visitor) override;
};


#endif //PASCAL_TRUEEXPR_H
