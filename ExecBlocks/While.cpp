#include "While.h"

While::While(BaseExpr *statement, BaseExecBlock *cycle_body, yy::location loc) : BaseExecBlock(loc) 
{
    statement_ = statement; 
    cycle_body_ = cycle_body;
}

void While::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr* While::GetStatement() const {
    return statement_;
}

BaseExecBlock* While::GetCycleBody() const {
    return cycle_body_;
}