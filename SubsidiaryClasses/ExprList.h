#ifndef MINI_JAVA_EXPRLIST_H
#define MINI_JAVA_EXPRLIST_H

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"
#include <vector>

class ExprList {
  public:
    std::vector<BaseExpr*> expressions;
    explicit ExprList(BaseExpr* expression);
    void addExpr(BaseExpr* expression);
};


#endif //MINI_JAVA_EXPRLIST_H
