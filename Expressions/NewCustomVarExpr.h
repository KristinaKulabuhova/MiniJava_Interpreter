#ifndef MINI_JAVA_NEWCUSTOMVAREXPR_H
#define MINI_JAVA_NEWCUSTOMVAREXPR_H

#include "BaseElements/BaseExpr.h"

class NewCustomVarExpr : public BaseExpr {
  public:
    std::string class_name;
    explicit NewCustomVarExpr(std::string class_name);
    ~NewCustomVarExpr() override = default;
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_NEWCUSTOMVAREXPR_H
