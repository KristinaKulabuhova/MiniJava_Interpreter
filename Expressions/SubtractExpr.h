#pragma once

#include "BaseElements/BaseExpr.h"

class SubtractExpr : public BaseExpr
{
public:
  SubtractExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~SubtractExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
