#ifndef PASCAL_FIELDEXPR_H
#define PASCAL_FIELDEXPR_H

#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr {
  public:
    std::string name;
    BaseExpr* index;

    explicit FieldExpr(std::string name, BaseExpr* index = nullptr);
    int Accept(Visitor& visitor) override;
    ~FieldExpr() override;
};


#endif //PASCAL_FIELDEXPR_H
