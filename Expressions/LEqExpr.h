#pragma once

#include "BaseElements/BaseExpr.h"

class LEqExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    LEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~LEqExpr() override;
    void Accept(Visitor& visitor) override;
};


