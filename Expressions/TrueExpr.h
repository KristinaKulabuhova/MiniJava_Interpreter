
#pragma once
#include "BaseElements/BaseExpr.h"

class TrueExpr : public BaseExpr{
  public:
    TrueExpr() = default;
    ~TrueExpr() override = default;
    void Accept(Visitor& visitor) override;
};

