#ifndef MINI_JAVA_METHODINVOCATION_H
#define MINI_JAVA_METHODINVOCATION_H

#include "BaseElements/BaseExpr.h"
#include "Visitors/Visitor.h"
#include "SubsidiaryClasses/Formals.h"
#include "BaseElements/BaseExecBlock.h"
#include "SubsidiaryClasses/ExprList.h"

class MethodInvocation : public BaseExpr, public BaseExecBlock {
  public:
    BaseExpr* callable_expr;
    std::string name;
    ExprList* arguments;
    
    MethodInvocation(BaseExpr* callable_expr, std::string name, ExprList* arguments);
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_METHODINVOCATION_H
