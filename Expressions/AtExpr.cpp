#include "AtExpr.h"

AtExpr::AtExpr(BaseExpr *array, BaseExpr *index, yy::location loc) : BaseExpr(loc)
{
    array_ = array;
    index_ = index;
}

void AtExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr *AtExpr::GetArray() const
{
    return array_;
}

BaseExpr *AtExpr::GetIndex() const
{
    return index_;
}