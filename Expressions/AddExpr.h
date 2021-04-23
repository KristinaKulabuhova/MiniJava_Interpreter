#pragma once

#include "BaseElements/BaseExpr.h"

class AddExpr : public BaseExpr {
  public:
    AddExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    ~AddExpr() override;
    void Accept(Visitor& visitor) override;
};


