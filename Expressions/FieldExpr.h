#pragma once
#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr
{
public:
  explicit FieldExpr(std::string name, yy::location loc);
  ~FieldExpr() override = default;

  void Accept(Visitor &visitor) override;

  const std::string& GetName() const;

private:
  std::string name_;
};
