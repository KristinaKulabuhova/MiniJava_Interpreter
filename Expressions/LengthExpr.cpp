#include "LengthExpr.h"

LengthExpr::LengthExpr(BaseExpr* array) : array(array) {}

LengthExpr::~LengthExpr() {
    delete array;
}

void LengthExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
