#ifndef PASCAL_VAREXPR_H
#define PASCAL_VAREXPR_H

#include "BaseElements/BaseExpr.h"

class VarExpr : public BaseExpr {
  public:
    std::string name;
    BaseExpr* index;
    explicit VarExpr(std::string name, BaseExpr* index = nullptr);
    int Accept(Visitor& visitor) override;
    ~VarExpr() override;
};


#endif //PASCAL_VAREXPR_H
