#pragma once

#include "BaseElements/BaseExpr.h"

class NotExpr : public BaseExpr {
  public:
    BaseExpr* p_expr;
    explicit NotExpr(BaseExpr* p_expr);
    ~NotExpr() override;
    void Accept(Visitor& visitor) override;
};

