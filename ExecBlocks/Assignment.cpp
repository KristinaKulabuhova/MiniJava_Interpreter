#include "Assignment.h"

Assignment::Assignment(IdentExpr *to, BaseExpr *from) : to_(to), from_(from) {}

Assignment::~Assignment()
{
    delete to_;
    delete from_;
}

IdentExpr* Assignment::GetTo() const {
      return to_;
    }

BaseExpr* Assignment::GetFrom() const {
      return from_;
    }

void Assignment::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
