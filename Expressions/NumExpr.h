#pragma once
#include "BaseElements/BaseExpr.h"

class NumExpr : public BaseExpr {
  public:
    int32_t value;
    explicit NumExpr(const std::string& number);
    ~NumExpr() override = default;
    void Accept(Visitor& visitor) override;
};

