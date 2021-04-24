#pragma once

#include "BaseElements/BaseExpr.h"

class ModExpr : public BaseExpr
{
public:
  ModExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~ModExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
