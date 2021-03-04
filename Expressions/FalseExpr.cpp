#include "FalseExpr.h"

int FalseExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
