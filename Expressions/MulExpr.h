#ifndef PARSEREXAMPLE_MULEXPR_H
#define PARSEREXAMPLE_MULEXPR_H

#include "BaseElements/BaseExpr.h"

class MulExpr : BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    MulExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~MulExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_MULEXPR_H
