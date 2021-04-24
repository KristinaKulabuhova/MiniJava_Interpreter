#pragma once
#include "BaseElements/BaseExpr.h"

class NumExpr : public BaseExpr
{
public:
  explicit NumExpr(const std::string &number);
  ~NumExpr() override = default;

  void Accept(Visitor &visitor) override;

public:
  int32_t value;
};
