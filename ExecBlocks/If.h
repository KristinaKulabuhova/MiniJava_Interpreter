#pragma once

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

class If : public BaseExecBlock {
  public:
    If(BaseExpr* statement, BaseExecBlock* true_branch, BaseExecBlock* false_branch, yy::location loc);
    ~If() override = default;

    void Accept(Visitor& visitor) override;

    BaseExecBlock* GetFalseBranch() const;
    BaseExecBlock* GetTrueBranch() const;
    BaseExpr* GetStatement() const;

  private:
    BaseExpr* statement;
    BaseExecBlock* true_branch;
    BaseExecBlock* false_branch;
};


