#include "NewCustomVarExpr.h"

NewCustomVarExpr::NewCustomVarExpr(std::string class_name, yy::location loc) : BaseExpr(loc)
{
    class_name_ = std::move(class_name);
}

void NewCustomVarExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

std::string NewCustomVarExpr::GetName() const {
    return class_name_;
}