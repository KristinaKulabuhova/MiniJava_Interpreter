#ifndef LENGTH_H
#define LENGTH_H

#include "BaseElements/BaseExpr.h"

class LengthExpr : public BaseExpr {
  public:
    BaseExpr* array;
    LeqExpr(BaseExpr* array);
    ~LeqExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif
