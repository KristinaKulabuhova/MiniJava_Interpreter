#include "Block.h"

Block::Block(ExecCode *exec_code_, yy::location loc) : BaseExecBlock(loc)
{
    exec_code = exec_code_;
}

void Block::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

ExecCode* Block::GetExecCode() const {
    return exec_code;
}
