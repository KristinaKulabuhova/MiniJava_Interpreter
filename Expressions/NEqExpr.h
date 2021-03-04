#ifndef PARSEREXAMPLE_NEQEXPR_H
#define PARSEREXAMPLE_NEQEXPR_H


#include "BaseElements/BaseExpr.h"

class NEqExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    NEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~NEqExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_NEQEXPR_H
