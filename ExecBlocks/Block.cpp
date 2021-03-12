#include "Block.h"

Block::Block(ExecCode *exec_code) : exec_code(exec_code) {}

int Block::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Block::~Block() {
    delete exec_code;
}
