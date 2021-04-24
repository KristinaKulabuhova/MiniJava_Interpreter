#pragma once

#include "BaseElements/BaseExpr.h"

class GreaterExpr : public BaseExpr
{
public:
  GreaterExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~GreaterExpr() override;
  
  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
