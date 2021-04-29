#include "AtExpr.h"

AtExpr::AtExpr(BaseExpr *array, BaseExpr *index) : array(array), index(index) {}

AtExpr::~AtExpr()
{
    delete array;
    delete index;
}

void AtExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr* AtExpr::GetArray() const {
    return array;
}

BaseExpr* AtExpr::GetIndex() const {
    return index;
}