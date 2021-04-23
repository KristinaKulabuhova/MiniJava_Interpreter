#pragma once

#include "BaseElements/BaseExpr.h"
#include "Expressions/SimpleType.h"

class NewArrExpr : public BaseExpr {
  public:
    SimpleType* simple_type;
    BaseExpr* n_elements;
    NewArrExpr(SimpleType* simple_type, BaseExpr* n_elements);
    ~NewArrExpr() override;
    void Accept(Visitor& visitor) override;
};

