#include "NewArrExpr.h"

NewArrExpr::NewArrExpr(SimpleType *simple_type, BaseExpr *n_elements, yy::location loc) : BaseExpr(loc)
{
    simple_type_ = simple_type;
    n_elements_ = n_elements;
}

void NewArrExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

  SimpleType* NewArrExpr::GetType() const {
      return simple_type_;
  }

  BaseExpr* NewArrExpr::GetElement() const {
      return n_elements_;
  }
