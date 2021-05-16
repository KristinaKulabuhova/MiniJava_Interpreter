#include "FieldExpr.h"

void FieldExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

FieldExpr::FieldExpr(std::string name, yy::location loc) : BaseExpr(loc)
{
    name_ = std::move(name);
}

const std::string& FieldExpr::GetName() const
{
    return name_;
}
