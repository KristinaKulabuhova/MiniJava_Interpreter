#pragma once

#include "BaseElements/BaseExpr.h"

class DivExpr : public BaseExpr
{
public:
  DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc);
  ~DivExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr *GetLeft() const;
  BaseExpr *GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
