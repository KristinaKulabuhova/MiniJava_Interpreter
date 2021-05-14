#pragma once

#include "BaseElements/BaseExpr.h"

class TrueExpr : public BaseExpr
{
public:
  TrueExpr(yy::location loc);
  ~TrueExpr() override = default;

  void Accept(Visitor &visitor) override;
};
