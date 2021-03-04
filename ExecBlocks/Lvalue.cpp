#include "Lvalue.h"

Lvalue::Lvalue(std::variant<VarExpr *, FieldExpr *> lvalue) : lvalue(lvalue) {}
