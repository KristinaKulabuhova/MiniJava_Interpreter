#ifndef PARSEREXAMPLE_LESSEXPR_H
#define PARSEREXAMPLE_LESSEXPR_H

#include "BaseElements/BaseExpr.h"

class LessExpr : BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    LessExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~LessExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_LESSEXPR_H
