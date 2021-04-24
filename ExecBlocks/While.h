#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock
{
public:
  While(BaseExpr *statement, BaseExecBlock *cycle_body);
  ~While() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *statement;
  BaseExecBlock *cycle_body;
};
