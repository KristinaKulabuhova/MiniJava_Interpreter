#pragma once
#include "BaseElements/BaseExpr.h"

class EqExpr : public BaseExpr
{
public:
  EqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~EqExpr() override;
  
  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
