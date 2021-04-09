#include "Lvalue.h"

Lvalue::Lvalue(std::variant<VarExpr *, FieldExpr *> lvalue) : lvalue(lvalue) {}

int Lvalue::Accept(Visitor &visitor) {
    if (std::holds_alternative<VarExpr*>(lvalue)) {
        std::get<VarExpr*>(lvalue)->Accept(visitor);
    } else if (std::holds_alternative<FieldExpr*>(lvalue)) {
        std::get<FieldExpr*>(lvalue)->Accept(visitor);
    }
    return 0;
}
