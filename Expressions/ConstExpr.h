#ifndef PARSEREXAMPLE_CONSTEXPR_H
#define PARSEREXAMPLE_CONSTEXPR_H

#include "BaseElements/BaseExpr.h"

class ConstExpr : BaseExpr {
  public:
    var_t value;
    explicit ConstExpr(const std::string& tmp_val);
    ~ConstExpr() override = default;
    var_t Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_CONSTEXPR_H
