#include "LengthExpr.h"

LengthExpr::LengthExpr(BaseExpr *array) : array(array) {}

void LengthExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

 BaseExpr* LengthExpr::GetArray() const {
    return array;
 }