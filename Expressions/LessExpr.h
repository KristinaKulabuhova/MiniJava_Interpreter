#pragma once

#include "BaseElements/BaseExpr.h"

class LessExpr : public BaseExpr
{
public:
  LessExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~LessExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
