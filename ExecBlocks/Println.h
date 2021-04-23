#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Println : public BaseExecBlock {
  public:
    BaseExpr* expression;

    explicit Println(BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~Println() override;
};

