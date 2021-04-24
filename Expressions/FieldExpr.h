#pragma once
#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr
{
public:
  explicit FieldExpr(std::string name);
  ~FieldExpr() = default;

  void Accept(Visitor &visitor) override;

public:
  std::string name;
};
