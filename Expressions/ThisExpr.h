#ifndef PASCAL_THISEXPR_H
#define PASCAL_THISEXPR_H

#include "BaseElements/BaseExpr.h"

class ThisExpr : public BaseExpr {
  public:
    ThisExpr() = default;
    int Accept(Visitor& visitor) override;
    ~ThisExpr() override = default;
};


#endif //PASCAL_THISEXPR_H
