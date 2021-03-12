#include "NewArrExpr.h"

NewArrExpr::NewArrExpr(VarType simple_type, BaseExpr *n_elements) : simple_type(simple_type), n_elements(n_elements) {}

NewArrExpr::~NewArrExpr() {
    delete n_elements;
}

int NewArrExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
