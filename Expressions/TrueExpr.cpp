#include "TrueExpr.h"

int TrueExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
