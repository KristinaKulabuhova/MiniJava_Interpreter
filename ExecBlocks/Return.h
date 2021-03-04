#ifndef PASCAL_RETURN_H
#define PASCAL_RETURN_H

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Return : public BaseExecBlock {
  public:
    BaseExpr* expression;
    explicit Return(BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~Return() override;
};


#endif //PASCAL_RETURN_H
