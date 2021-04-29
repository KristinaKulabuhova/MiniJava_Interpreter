#pragma once

#include "BaseElements/BaseExpr.h"

class ModExpr : public BaseExpr
{
public:
  ModExpr(BaseExpr *p_lhs, BaseExpr *p_rhs);
  ~ModExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetLeft() const;
  BaseExpr* GetRight() const;

private:
  BaseExpr *p_lhs;
  BaseExpr *p_rhs;
};
