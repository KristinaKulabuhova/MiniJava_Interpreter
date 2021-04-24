#pragma once

#include "BaseElements/BaseExpr.h"

class NewCustomVarExpr : public BaseExpr
{
public:
  explicit NewCustomVarExpr(std::string class_name);
  ~NewCustomVarExpr() = default;

  void Accept(Visitor &visitor) override;

public:
  std::string class_name;
};
