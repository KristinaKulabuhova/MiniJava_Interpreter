#ifndef PARSEREXAMPLE_SUBTRACTEXPR_H
#define PARSEREXAMPLE_SUBTRACTEXPR_H

#include "BaseElements/BaseExpr.h"

class SubtractExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    SubtractExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~SubtractExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_SUBTRACTEXPR_H
