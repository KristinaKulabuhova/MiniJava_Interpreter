#pragma once

#include "BaseElements/BaseExpr.h"

class NotExpr : public BaseExpr
{
public:
  explicit NotExpr(BaseExpr *p_expr);
  ~NotExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetExpression() const;

private:
  BaseExpr *p_expr;
};
