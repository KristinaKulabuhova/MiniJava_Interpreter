#include "If.h"

If::If(BaseExpr *statement, ExecCode *true_branch, ExecCode *false_branch) :
statement(statement), true_branch(true_branch), false_branch(false_branch) {}

void If::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

If::~If() {
    delete statement;
    delete true_branch;
    delete false_branch;
}
