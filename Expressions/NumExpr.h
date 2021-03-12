#ifndef MINI_JAVA_NUMEXPR_H
#define MINI_JAVA_NUMEXPR_H

#include "BaseElements/BaseExpr.h"

class NumExpr : public BaseExpr {
  public:
    int32_t value;
    explicit NumExpr(const std::string& number);
    ~NumExpr() override = default;
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_NUMEXPR_H
