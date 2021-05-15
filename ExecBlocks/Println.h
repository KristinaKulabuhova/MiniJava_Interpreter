#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Println : public BaseExecBlock
{
public:
  explicit Println(BaseExpr *expression, yy::location loc);
  ~Println() override = default;

  void Accept(Visitor &visitor) override;

  BaseExpr* GetExpression() const;

private:
  BaseExpr *expression_;
};
