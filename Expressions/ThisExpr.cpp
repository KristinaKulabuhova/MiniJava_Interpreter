#include "ThisExpr.h"

int ThisExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
