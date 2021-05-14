#pragma once
#include "BaseElements/BaseExpr.h"

class NumExpr : public BaseExpr
{
public:
  explicit NumExpr(const std::string &number, yy::location loc);
  ~NumExpr() override = default;

  void Accept(Visitor &visitor) override;

  int32_t GetValue() const;

private:
  int32_t value;
};
