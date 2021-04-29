
#pragma once
#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"
#include <vector>

class ExprList
{
public:
  explicit ExprList(BaseExpr *expression);
  ~ExprList();

  void addExpr(BaseExpr *expression);

  std::vector<BaseExpr *> GetExpr() const;

private:
  std::vector<BaseExpr *> expressions;
};
