#pragma once

#include "BaseElements/BaseExpr.h"

class NewCustomVarExpr : public BaseExpr
{
public:
  explicit NewCustomVarExpr(std::string class_name);
  ~NewCustomVarExpr() override = default;

  void Accept(Visitor &visitor) override;

  std::string GetName() const;

private:
  std::string class_name;
};
