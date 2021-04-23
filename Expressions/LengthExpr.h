#pragma once

#include "BaseElements/BaseExpr.h"

class LengthExpr : public BaseExpr {
  public:
    BaseExpr* array;
    
    explicit LengthExpr(BaseExpr* array);
    ~LengthExpr() override;
    void Accept(Visitor& visitor) override;
};

