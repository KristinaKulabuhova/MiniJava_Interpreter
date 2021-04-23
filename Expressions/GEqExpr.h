#pragma once

#include "BaseElements/BaseExpr.h"

class GEqExpr : public BaseExpr{
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    GEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~GEqExpr() override;
    void Accept(Visitor& visitor) override;
};



