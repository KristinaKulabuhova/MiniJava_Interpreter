#pragma once

#include "BaseElements/BaseExpr.h"

class AndExpr : public BaseExpr
{
public:
  AndExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~AndExpr() override;

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
