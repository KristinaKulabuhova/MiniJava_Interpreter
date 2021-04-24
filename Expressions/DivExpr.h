#pragma once

#include "BaseElements/BaseExpr.h"

class DivExpr : public BaseExpr
{
public:
  DivExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~DivExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
