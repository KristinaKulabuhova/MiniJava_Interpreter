#pragma once

#include "BaseElements/BaseExpr.h"

class NewCustomVarExpr : public BaseExpr
{
public:
  explicit NewCustomVarExpr(std::string class_name, yy::location loc);
  ~NewCustomVarExpr() override = default;

  void Accept(Visitor &visitor) override;

  std::string GetName() const;

private:
  std::string class_name;
};
