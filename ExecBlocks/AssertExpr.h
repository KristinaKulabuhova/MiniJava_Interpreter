#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class AssertExpr : public BaseExecBlock {
  public:
    BaseExpr* expression;
    explicit AssertExpr(BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~AssertExpr() override;
};


