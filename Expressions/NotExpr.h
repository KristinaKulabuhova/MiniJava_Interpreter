#ifndef PARSEREXAMPLE_NOTEXPR_H
#define PARSEREXAMPLE_NOTEXPR_H

#include "BaseElements/BaseExpr.h"

class NotExpr : BaseExpr {
  public:
    BaseExpr* p_expr;
    explicit NotExpr(BaseExpr* p_expr);
    ~NotExpr() override;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_NOTEXPR_H
