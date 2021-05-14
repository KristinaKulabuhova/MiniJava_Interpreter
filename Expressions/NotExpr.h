#pragma once

#include "BaseElements/BaseExpr.h"

class NotExpr : public BaseExpr
{
public:
  explicit NotExpr(BaseExpr *p_expr, yy::location loc);
  ~NotExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetExpression() const;

private:
  BaseExpr *p_expr;
};
