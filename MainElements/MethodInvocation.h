#ifndef MINI_JAVA_METHODINVOCATION_H
#define MINI_JAVA_METHODINVOCATION_H

#include "BaseElements/BaseExpr.h"
#include "Visitors/Visitor.h"
#include "SubsidiaryClasses/Formals.h"
#include "BaseElements/BaseExecBlock.h"
#include "SubsidiaryClasses/ExprList.h"
#include "Expressions/FieldExpr.h"

class MethodInvocation : public BaseExpr, public BaseExecBlock {
  public:
    BaseExpr* callable_expr; // nullptr if it is "this"
    std::string name;
    ExprList* arguments;
    
    MethodInvocation(BaseExpr* callable_expr, std::string name, ExprList* arguments);
    explicit MethodInvocation(FieldExpr* callable_expr, ExprList* expr_list = nullptr);
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_METHODINVOCATION_H
