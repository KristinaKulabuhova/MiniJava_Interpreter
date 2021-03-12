#include "AtExpr.h"

AtExpr::AtExpr(BaseExpr *array, BaseExpr *index) : array(array), index(index) {}

AtExpr::~AtExpr() {
    delete array;
    delete index;
}

int AtExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
