#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "ExecBlocks/ExecCode.h"

class Block : public BaseExecBlock {
  public:
    ExecCode* exec_code;
    Block(ExecCode* exec_code);
    void Accept(Visitor& visitor) override;
    ~Block() override;
};


