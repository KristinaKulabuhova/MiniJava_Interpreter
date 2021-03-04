#ifndef PARSEREXAMPLE_LEQEXPR_H
#define PARSEREXAMPLE_LEQEXPR_H

#include "BaseElements/BaseExpr.h"

class LEqExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    LEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~LEqExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_LEQEXPR_H
