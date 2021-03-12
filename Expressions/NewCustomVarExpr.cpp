#include "NewCustomVarExpr.h"

NewCustomVarExpr::NewCustomVarExpr(std::string class_name) : class_name(std::move(class_name)) {}

int NewCustomVarExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
