#pragma once

#include "BaseElements/BaseExpr.h"

class NEqExpr : public BaseExpr
{
public:
  NEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc);
  ~NEqExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs_;
  BaseExpr *p_rhs_;
};
