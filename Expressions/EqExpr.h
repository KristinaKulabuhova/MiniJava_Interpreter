#ifndef PARSEREXAMPLE_EQEXPR_H
#define PARSEREXAMPLE_EQEXPR_H

#include "BaseElements/BaseExpr.h"

class EqExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    EqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~EqExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_EQEXPR_H
