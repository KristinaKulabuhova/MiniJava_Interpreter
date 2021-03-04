#ifndef LENGTH_H
#define LENGTH_H

#include "BaseElements/BaseExpr.h"

class LengthExpr : public BaseExpr {
  public:
    BaseExpr* array;
    LengthExpr(BaseExpr* array);
    ~LengthExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif
