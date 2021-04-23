#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Return : public BaseExecBlock {
  public:
    BaseExpr* expression;
    explicit Return(BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~Return() override;
};


