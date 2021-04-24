#include "Block.h"

Block::Block(ExecCode *exec_code) : exec_code(exec_code) {}

Block::~Block()
{
    delete exec_code;
}

void Block::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
