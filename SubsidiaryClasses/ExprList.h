
#pragma once
#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"
#include <vector>

class ExprList {
  public:
    std::vector<BaseExpr*> expressions;
    explicit ExprList(BaseExpr* expression);
    void addExpr(BaseExpr* expression);
};

