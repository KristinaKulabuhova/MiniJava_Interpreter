#ifndef PARSEREXAMPLE_GEQEXPR_H
#define PARSEREXAMPLE_GEQEXPR_H

#include "BaseElements/BaseExpr.h"

class GeqExpr : public BaseExpr{
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    GeqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~GeqExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_GEQEXPR_H
