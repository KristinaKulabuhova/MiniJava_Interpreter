#pragma once

#include "BaseElements/BaseExpr.h"

class NewCustomVarExpr : public BaseExpr {
  public:
    std::string class_name;
    explicit NewCustomVarExpr(std::string class_name);
    ~NewCustomVarExpr() override = default;
    void Accept(Visitor& visitor) override;
};


