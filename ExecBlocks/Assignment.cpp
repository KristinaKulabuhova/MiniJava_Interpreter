#include "Assignment.h"

void Assignment::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

Assignment::~Assignment() {
    delete to;
    delete from;
}

Assignment::Assignment(BaseExpr *to, BaseExpr *from) : to(to), from(from) {}
