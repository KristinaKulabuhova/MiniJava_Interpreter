#pragma once

#include "BaseElements/BaseExpr.h"
#include "Expressions/SimpleType.h"

class NewArrExpr : public BaseExpr
{
public:
  NewArrExpr(SimpleType *simple_type, BaseExpr *n_elements);
  ~NewArrExpr() override;
  
  void Accept(Visitor &visitor) override;

public:
  SimpleType *simple_type;
  BaseExpr *n_elements;
};
