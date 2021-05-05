#include "Block.h"

Block::Block(ExecCode *exec_code) : exec_code(exec_code) {}

void Block::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

ExecCode* Block::GetExecCode() const {
    return exec_code;
}
