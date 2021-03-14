#ifndef PASCAL_LVALUE_H
#define PASCAL_LVALUE_H

#include "Expressions/VarExpr.h"
#include "Expressions/FieldExpr.h"

class Lvalue {
  public:
    std::variant<VarExpr*, FieldExpr*> lvalue;
    explicit Lvalue(std::variant<VarExpr*, FieldExpr*> lvalue);
    ~Lvalue() = default;
};


#endif //PASCAL_LVALUE_H