#ifndef PARSEREXAMPLE_MODEXPR_H
#define PARSEREXAMPLE_MODEXPR_H

#include "BaseElements/BaseExpr.h"

class ModExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    ModExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~ModExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_MODEXPR_H
