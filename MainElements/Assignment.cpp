#include "Assignment.h"

Assignment::Assignment(std::string var_name_, BaseExpr *expression) : var_name_(std::move(var_name_)), expression(expression) {}

void Assignment::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

Assignment::~Assignment() {
    delete expression;
}
