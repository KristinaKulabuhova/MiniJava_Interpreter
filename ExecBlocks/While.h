#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock {
  public:
    BaseExpr* statement;
    BaseExecBlock* cycle_body;
    While(BaseExpr* statement, BaseExecBlock* cycle_body);
    void Accept(Visitor& visitor) override;
    ~While() override;
};


