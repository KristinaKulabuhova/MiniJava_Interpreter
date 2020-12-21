#ifndef PARSEREXAMPLE_LEQEXPR_H
#define PARSEREXAMPLE_LEQEXPR_H

#include "BaseElements/BaseExpr.h"

class LeqExpr : BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    LeqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~LeqExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_LEQEXPR_H
