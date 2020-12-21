#include "While.h"

While::While(BaseExpr *statement, ExecCode *cycle_body) : statement(statement), cycle_body(cycle_body) {}

void While::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

While::~While() {
    delete statement;
    delete cycle_body;
}
