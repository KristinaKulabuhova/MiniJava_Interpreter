#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class AssertExpr : public BaseExecBlock
{
public:
  explicit AssertExpr(BaseExpr *expression, yy::location loc);
  ~AssertExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetExpression() const;

private:
  BaseExpr *expression;
};
