#include "For.h"


void For::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

For::~For() {
    delete cycle_body;
}

For::For(std::string var_name, BaseExpr *lower_bound, BaseExpr *upper_bound, ExecCode *cycle_body) :
var_name(std::move(var_name)), lower_bound(lower_bound), upper_bound(upper_bound), cycle_body(cycle_body) {}
