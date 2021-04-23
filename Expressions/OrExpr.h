#pragma once
#include "BaseElements/BaseExpr.h"

class OrExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    OrExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~OrExpr() override;
    void Accept(Visitor& visitor) override;
};

