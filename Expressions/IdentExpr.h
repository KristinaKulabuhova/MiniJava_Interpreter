#pragma once

#include "BaseElements/BaseExpr.h"

#include "string"

class IdentExpr : public BaseExpr {
  public:
    std::string var_name_;
    explicit IdentExpr(std::string  var_name_);
    void Accept(Visitor& visitor) override;
};

