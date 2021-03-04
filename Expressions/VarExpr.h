#ifndef PASCAL_VAREXPR_H
#define PASCAL_VAREXPR_H

#include "BaseElements/BaseExpr.h"

class VarExpr : public BaseExpr {
  public:
    std::string name;
    BaseExpr* index;
    VarExpr(std::string name);
    VarExpr(std::string name, BaseExpr* index);
    int Accept(Visitor& visitor) override;
    ~VarExpr() override;
};


#endif //PASCAL_VAREXPR_H
