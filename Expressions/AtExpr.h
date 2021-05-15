#pragma once
#include "BaseElements/BaseExpr.h"

class AtExpr : public BaseExpr
{
public:
  AtExpr(BaseExpr *array, BaseExpr *index, yy::location loc);
  ~AtExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr *GetArray() const;
  BaseExpr *GetIndex() const;

private:
  BaseExpr *array_;
  BaseExpr *index_;
};
