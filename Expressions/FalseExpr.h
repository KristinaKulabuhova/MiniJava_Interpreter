#pragma once

#include "BaseElements/BaseExpr.h"

class FalseExpr : public BaseExpr
{
public:
  FalseExpr(yy::location loc);
  ~FalseExpr() override = default;

  void Accept(Visitor &visitor) override;
};
