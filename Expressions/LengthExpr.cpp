#include "LengthExpr.h"

LengthExpr::LengthExpr(BaseExpr* array) : array(array) {}

LengthExpr::~LengthExpr() {
    delete array;
}

var_t LengthExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
