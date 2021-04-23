#include "FalseExpr.h"

void FalseExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
