#include "TrueExpr.h"

void TrueExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
