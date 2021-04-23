#pragma once
#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr {
  public:
    std::string name;

    explicit FieldExpr(std::string name);
    void Accept(Visitor& visitor) override;
};


