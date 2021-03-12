#ifndef PASCAL_BLOCK_H
#define PASCAL_BLOCK_H

#include "BaseElements/BaseExecBlock.h"
#include "ExecBlocks/ExecCode.h"

class Block : public BaseExecBlock {
  public:
    ExecCode* exec_code;
    Block(ExecCode* exec_code);
    int Accept(Visitor& visitor) override;
    ~Block() override;
};


#endif //PASCAL_BLOCK_H
