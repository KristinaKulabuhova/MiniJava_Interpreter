#include "Assignment.h"

int Assignment::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Assignment::~Assignment() {
    delete to;
    delete from;
}

Assignment::Assignment(BaseExpr *to, BaseExpr *from) : to(to), from(from) {}
