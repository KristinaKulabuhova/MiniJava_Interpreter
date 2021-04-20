#ifndef PASCAL_FIELDEXPR_H
#define PASCAL_FIELDEXPR_H

#include "BaseElements/BaseExpr.h"

class FieldExpr : public BaseExpr {
  public:
    std::string name;

    explicit FieldExpr(std::string name);
    int Accept(Visitor& visitor) override;
};


#endif //PASCAL_FIELDEXPR_H
