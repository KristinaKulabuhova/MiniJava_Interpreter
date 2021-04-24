#pragma once

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

class If : public BaseExecBlock {
  public:
    If(BaseExpr* statement, BaseExecBlock* true_branch, BaseExecBlock* false_branch = nullptr);
    ~If() override;

    void Accept(Visitor& visitor) override;

  public:
    BaseExpr* statement;
    BaseExecBlock* true_branch;
    BaseExecBlock* false_branch;
};


