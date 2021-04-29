#pragma once
#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr
{
public:
  explicit FieldExpr(std::string name);
  ~FieldExpr() override = default;

  void Accept(Visitor &visitor) override;

  std::string GetName() const;

private:
  std::string name_;
};
