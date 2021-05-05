#pragma once

#include "BaseElements/BaseExpr.h"
#include "string"

class IdentExpr : public BaseExpr
{
public:
  explicit IdentExpr(std::string var_name_);
  ~IdentExpr() override = default;

  void Accept(Visitor &visitor) override;

  std::string GetName() const;

private:
  std::string var_name_;
};
