#pragma once
#include "BaseElements/BaseExpr.h"

class MulExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    MulExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~MulExpr() override;
    void Accept(Visitor& visitor) override;
};
