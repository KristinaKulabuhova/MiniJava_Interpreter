#ifndef PARSEREXAMPLE_IDENTEXPR_H
#define PARSEREXAMPLE_IDENTEXPR_H

#include "BaseElements/BaseExpr.h"

#include "string"

class IdentExpr : public BaseExpr {
  public:
    std::string var_name_;
    explicit IdentExpr(std::string  var_name_);
    int Accept(Visitor& visitor) override;
};


#endif 