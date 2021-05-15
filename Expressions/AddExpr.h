#pragma once

#include "BaseElements/BaseExpr.h"

class AddExpr : public BaseExpr
{
public:
  AddExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc);
  ~AddExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr *GetLeft() const;
  BaseExpr *GetRight() const;

private:
  BaseExpr *p_lhs_;
  BaseExpr *p_rhs_;
};
