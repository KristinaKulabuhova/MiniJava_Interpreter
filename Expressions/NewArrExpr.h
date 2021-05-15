#pragma once

#include "BaseElements/BaseExpr.h"
#include "Expressions/SimpleType.h"

class NewArrExpr : public BaseExpr
{
public:
  NewArrExpr(SimpleType *simple_type, BaseExpr *n_elements, yy::location loc);
  ~NewArrExpr() override = default;
  
  void Accept(Visitor &visitor) override;

  SimpleType* GetType() const;
  BaseExpr* GetElement() const;

private:
  SimpleType *simple_type_;
  BaseExpr *n_elements_;
};
