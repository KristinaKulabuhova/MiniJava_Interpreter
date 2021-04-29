#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock
{
public:
  While(BaseExpr *statement, BaseExecBlock *cycle_body);
  ~While() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetStatement() const;
  BaseExecBlock* GetCycleBody() const;

private:
  BaseExpr *statement;
  BaseExecBlock *cycle_body;
};
