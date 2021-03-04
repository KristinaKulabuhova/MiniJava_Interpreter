#ifndef PASCAL_ASSERTEXPR_H
#define PASCAL_ASSERTEXPR_H

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class AssertExpr : public BaseExecBlock {
  public:
    BaseExpr* expression;
    explicit AssertExpr(BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~AssertExpr() override;
};


#endif //PASCAL_ASSERTEXPR_H
