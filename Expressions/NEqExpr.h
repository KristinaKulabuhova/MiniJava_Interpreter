#pragma once

#include "BaseElements/BaseExpr.h"

class NEqExpr : public BaseExpr
{
public:
  NEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~NEqExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
