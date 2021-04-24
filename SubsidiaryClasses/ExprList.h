
#pragma once
#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"
#include <vector>

class ExprList
{
public:
  explicit ExprList(BaseExpr *expression);
  ~ExprList() = default;

  void addExpr(BaseExpr *expression);

public:
  std::vector<BaseExpr *> expressions;
};
