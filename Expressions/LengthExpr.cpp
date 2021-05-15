#include "LengthExpr.h"

LengthExpr::LengthExpr(BaseExpr *array, yy::location loc) : BaseExpr(loc)
{
    array_ = array;
}

void LengthExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *LengthExpr::GetArray() const
{
    return array_;
}