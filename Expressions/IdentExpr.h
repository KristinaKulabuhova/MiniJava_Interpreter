#pragma once

#include "BaseElements/BaseExpr.h"
#include "string"

class IdentExpr : public BaseExpr
{
public:
  explicit IdentExpr(std::string var_name_);
  ~IdentExpr() override;

  void Accept(Visitor &visitor) override;

public:
  std::string var_name_;
};
