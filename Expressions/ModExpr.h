#ifndef PARSEREXAMPLE_LESSEXPR_H
#define PARSEREXAMPLE_LESSEXPR_H

#include "BaseElements/BaseExpr.h"

class ModExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    ModExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~ModExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif