#pragma once
#include "BaseElements/BaseExpr.h"
#include "Visitors/Visitor.h"
#include "SubsidiaryClasses/Formals.h"
#include "BaseElements/BaseExecBlock.h"
#include "SubsidiaryClasses/ExprList.h"
#include "Expressions/FieldExpr.h"

class MethodInvocation : public BaseExpr, public BaseExecBlock
{
public:
  MethodInvocation(BaseExpr *callable_expr, std::string name, ExprList *arguments);
  explicit MethodInvocation(FieldExpr *callable_expr, ExprList *expr_list = nullptr);

  void Accept(Visitor &visitor) override;

public:
  BaseExpr *callable_expr; // nullptr if it is "this"
  std::string name;
  ExprList *arguments;
};
