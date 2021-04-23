#pragma once

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

class If : public BaseExecBlock {
  public:
    BaseExpr* statement;
    BaseExecBlock* true_branch;
    BaseExecBlock* false_branch;
    If(BaseExpr* statement, BaseExecBlock* true_branch, BaseExecBlock* false_branch = nullptr);
    void Accept(Visitor& visitor) override;
    ~If() override;
};


