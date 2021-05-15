#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock
{
public:
  While(BaseExpr *statement, BaseExecBlock *cycle_body, yy::location loc);
  ~While() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetStatement() const;
  BaseExecBlock* GetCycleBody() const;

private:
  BaseExpr *statement_;
  BaseExecBlock *cycle_body_;
};
