#pragma once

#include "BaseElements/BaseExpr.h"

class SubtractExpr : public BaseExpr
{
public:
  SubtractExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~SubtractExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
