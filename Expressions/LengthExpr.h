#pragma once

#include "BaseElements/BaseExpr.h"

class LengthExpr : public BaseExpr
{
public:
  explicit LengthExpr(BaseExpr *array);
  ~LengthExpr() override;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetArray() const;

private:
  BaseExpr *array;
};
