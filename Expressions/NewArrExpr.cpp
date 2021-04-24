#include "NewArrExpr.h"

NewArrExpr::NewArrExpr(SimpleType *simple_type, BaseExpr *n_elements) : simple_type(simple_type), n_elements(n_elements) {}

NewArrExpr::~NewArrExpr()
{
    delete n_elements;
}

void NewArrExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
