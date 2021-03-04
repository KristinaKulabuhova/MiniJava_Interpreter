#ifndef PARSEREXAMPLE_DIVEXPR_H
#define PARSEREXAMPLE_DIVEXPR_H

#include "BaseElements/BaseExpr.h"

class DivExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    DivExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~DivExpr() override;
    int Accept(Visitor& visitor) override;
};

#endif //PARSEREXAMPLE_DIVEXPR_H
