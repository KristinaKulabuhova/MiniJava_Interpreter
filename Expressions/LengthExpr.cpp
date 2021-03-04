#include "LengthExpr.h"

LengthExpr::LengthExpr(BaseExpr* array) : array(array) {}

LengthExpr::~LengthExpr() {
    delete array;
}

int LengthExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
