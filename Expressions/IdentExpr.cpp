#include "IdentExpr.h"

#include <variant>

IdentExpr::IdentExpr(std::string var_name_) : var_name_(std::move(var_name_)) {}

void IdentExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}