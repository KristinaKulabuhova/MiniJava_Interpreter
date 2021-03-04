#ifndef PARSEREXAMPLE_OREXPR_H
#define PARSEREXAMPLE_OREXPR_H

#include "BaseElements/BaseExpr.h"

class OrExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    OrExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~OrExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_OREXPR_H
