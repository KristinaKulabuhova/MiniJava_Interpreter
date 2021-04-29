#include "NumExpr.h"

NumExpr::NumExpr(const std::string &number)
{
    value = std::stoi(number);
}

void NumExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

int32_t NumExpr::GetValue() const
{
    return value;
}