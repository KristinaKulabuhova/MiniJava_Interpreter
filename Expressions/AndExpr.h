#pragma once

#include "BaseElements/BaseExpr.h"

class AndExpr : public BaseExpr
{
public:
  AndExpr(BaseExpr *p_lhs, BaseExpr *p_rhs, yy::location loc);
  ~AndExpr() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr *GetLeft() const;
  BaseExpr *GetRight() const;

private:
  BaseExpr *p_lhs_;
  BaseExpr *p_rhs_;
};
