#ifndef PARSEREXAMPLE_GREATEREXPR_H
#define PARSEREXAMPLE_GREATEREXPR_H

#include "BaseElements/BaseExpr.h"

class GreaterExpr : BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    GreaterExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~GreaterExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_GREATEREXPR_H
