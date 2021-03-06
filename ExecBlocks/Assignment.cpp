#include "Assignment.h"

Assignment::Assignment(IdentExpr *to, BaseExpr *from, yy::location loc) : BaseExecBlock(loc)
{
  to_ = to; 
  from_ = from;
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
