#pragma once

#include "BaseElements/BaseExpr.h"

class FalseExpr : public BaseExpr {
  public:
    FalseExpr() = default;
    ~FalseExpr() override = default;
    void Accept(Visitor& visitor) override;
};


