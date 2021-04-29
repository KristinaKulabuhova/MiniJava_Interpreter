#pragma once

#include "BaseElements/BaseExpr.h"

class LEqExpr : public BaseExpr
{
public:
  LEqExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~LEqExpr() override;
  
  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
