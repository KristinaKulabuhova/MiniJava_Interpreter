#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Return : public BaseExecBlock
{
public:
  explicit Return(BaseExpr *expression);
  ~Return() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetExpression() const;

private:
  BaseExpr *expression;
};
