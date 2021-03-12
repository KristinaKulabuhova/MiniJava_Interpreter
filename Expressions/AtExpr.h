#ifndef MINI_JAVA_ATEXPR_H
#define MINI_JAVA_ATEXPR_H

#include "BaseElements/BaseExpr.h"

class AtExpr : public BaseExpr {
  public:
    BaseExpr* array;
    BaseExpr* index;
    AtExpr(BaseExpr* array, BaseExpr* index);
    ~AtExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_ATEXPR_H
