#pragma once
#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock
{
public:
  Assignment(BaseExpr *to, BaseExpr *from);
  ~Assignment() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *to;
  BaseExpr *from;
};
