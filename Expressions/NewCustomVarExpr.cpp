#include "NewCustomVarExpr.h"

NewCustomVarExpr::NewCustomVarExpr(std::string class_name) : class_name(std::move(class_name)) {}

void NewCustomVarExpr::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
