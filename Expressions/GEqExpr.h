#ifndef PARSEREXAMPLE_GEQEXPR_H
#define PARSEREXAMPLE_GEQEXPR_H

#include "BaseElements/BaseExpr.h"

class GEqExpr : public BaseExpr{
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    GEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~GEqExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_GEQEXPR_H
