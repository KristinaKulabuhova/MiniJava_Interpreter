#include "AddExpr.h"

AddExpr::AddExpr(BaseExpr *p_lhs, BaseExpr *p_rhs) : p_lhs(p_lhs), p_rhs(p_rhs) {}

AddExpr::~AddExpr() {
    delete p_lhs;
    delete p_rhs;
}

void AddExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

  BaseExpr* AddExpr::GetLeft() const {
      return p_lhs;
  }

  BaseExpr* AddExpr::GetRight() const {
      return p_rhs;
  }
