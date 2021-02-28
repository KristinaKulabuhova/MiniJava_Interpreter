#ifndef PARSEREXAMPLE_ADDEXPR_H
#define PARSEREXAMPLE_ADDEXPR_H

#include "BaseElements/BaseExpr.h"

class AddExpr : public BaseExpr {
  public:
    AddExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    ~AddExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif