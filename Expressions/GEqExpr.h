#pragma once

#include "BaseElements/BaseExpr.h"

class GEqExpr : public BaseExpr
{
public:
  GEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~GEqExpr() override;
  
  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
