#ifndef MINI_JAVA_NEWARREXPR_H
#define MINI_JAVA_NEWARREXPR_H

#include "BaseElements/BaseExpr.h"

class NewArrExpr : public BaseExpr {
  public:
    VarType simple_type;
    BaseExpr* n_elements;
    NewArrExpr(VarType simple_type, BaseExpr* n_elements);
    ~NewArrExpr() override;
    int Accept(Visitor& visitor) override;
};


#endif //MINI_JAVA_NEWARREXPR_H
