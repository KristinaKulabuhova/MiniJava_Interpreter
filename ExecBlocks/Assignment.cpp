#include "Assignment.h"

Assignment::Assignment(IdentExpr *to, BaseExpr *from) : to(to), from(from) {}

Assignment::~Assignment()
{
    delete to;
    delete from;
}

void Assignment::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
