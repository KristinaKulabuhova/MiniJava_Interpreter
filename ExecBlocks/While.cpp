#include "While.h"

While::While(BaseExpr *statement, ExecCode *cycle_body) : statement(statement), cycle_body(cycle_body) {}

int While::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

While::~While() {
    delete statement;
    delete cycle_body;
}
