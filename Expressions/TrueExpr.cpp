#include "TrueExpr.h"

TrueExpr::TrueExpr(yy::location loc) : BaseExpr(loc) {}

void TrueExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
