#ifndef PARSEREXAMPLE_ANDEXPR_H
#define PARSEREXAMPLE_ANDEXPR_H

#include "BaseElements/BaseExpr.h"

class AndExpr : public BaseExpr {
  public:
    BaseExpr* p_lhs;
    BaseExpr* p_rhs;
    AndExpr(BaseExpr* p_lhs, BaseExpr* p_rhs);
    ~AndExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_ANDEXPR_H
