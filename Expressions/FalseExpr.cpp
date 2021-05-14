#include "FalseExpr.h"

FalseExpr::FalseExpr(yy::location loc) : BaseExpr(loc) {}

void FalseExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
