#pragma once

#include "BaseElements/BaseExpr.h"

class MulExpr : public BaseExpr
{
public:
  MulExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc);
  ~MulExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
