#pragma once

#include "BaseElements/BaseExpr.h"

class LengthExpr : public BaseExpr
{
public:
  explicit LengthExpr(BaseExpr *array, yy::location loc);
  ~LengthExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr *GetArray() const;

private:
  BaseExpr *array;
};
