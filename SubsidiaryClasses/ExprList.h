
#pragma once
#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"
#include <vector>

class ExprList
{
public:
  explicit ExprList(BaseExpr *expression, yy::location loc);
  ~ExprList();

  void addExpr(BaseExpr *expression);

  std::vector<BaseExpr *> GetExpr() const;

private:
  std::vector<BaseExpr *> expressions;
  yy::location location_;
};
