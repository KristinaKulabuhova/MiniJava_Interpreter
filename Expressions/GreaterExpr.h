#pragma once

#include "BaseElements/BaseExpr.h"

class GreaterExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    GreaterExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~GreaterExpr() override;
    void Accept(Visitor& visitor) override;
};



