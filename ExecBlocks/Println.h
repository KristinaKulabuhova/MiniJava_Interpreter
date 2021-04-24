#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Println : public BaseExecBlock
{
public:
  explicit Println(BaseExpr *expression);
  ~Println() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *expression;
};
