#include "Block.h"

Block::Block(ExecCode *exec_code, yy::location loc) : BaseExecBlock(loc)
{
    exec_code_ = exec_code;
}

void Block::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

ExecCode* Block::GetExecCode() const {
    return exec_code_;
}
