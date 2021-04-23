#pragma once

#include "BaseElements/BaseExpr.h"

class NEqExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    NEqExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~NEqExpr() override;
    void Accept(Visitor& visitor) override;
};


