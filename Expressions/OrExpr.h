#ifndef PARSEREXAMPLE_OREXPR_H
#define PARSEREXAMPLE_OREXPR_H

#include "BaseElements/BaseExpr.h"

class OrExpr : BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    OrExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~OrExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_OREXPR_H
