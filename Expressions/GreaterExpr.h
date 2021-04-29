#pragma once

#include "BaseElements/BaseExpr.h"

class GreaterExpr : public BaseExpr
{
public:
  GreaterExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~GreaterExpr() override;
  
  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
