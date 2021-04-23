#pragma once
#include "BaseElements/BaseExpr.h"

class AtExpr : public BaseExpr {
  public:
    BaseExpr* array;
    BaseExpr* index;
    AtExpr(BaseExpr* array, BaseExpr* index);
    ~AtExpr() override;
    void Accept(Visitor& visitor) override;
};


