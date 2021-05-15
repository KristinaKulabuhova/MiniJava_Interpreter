#include "If.h"

If::If(BaseExpr *statement, BaseExecBlock *true_branch, BaseExecBlock *false_branch, yy::location loc) : BaseExecBlock(loc)
{
    statement_ = statement; 
    true_branch_ = true_branch;
    false_branch_ = false_branch;
}

void If::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExecBlock* If::GetFalseBranch() const {
    return false_branch_;
}

BaseExecBlock* If::GetTrueBranch() const {
    return true_branch_;
}

BaseExpr* If::GetStatement() const {
    return statement_;
}