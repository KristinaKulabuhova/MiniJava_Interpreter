#ifndef PARSEREXAMPLE_NOTEXPR_H
#define PARSEREXAMPLE_NOTEXPR_H

#include "BaseElements/BaseExpr.h"

class NotExpr : public BaseExpr {
  public:
    BaseExpr* p_expr;
    explicit NotExpr(BaseExpr* p_expr);
    ~NotExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_NOTEXPR_H
