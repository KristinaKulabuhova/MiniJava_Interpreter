#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "ExecBlocks/ExecCode.h"

class Block : public BaseExecBlock
{
public:
  Block(ExecCode *exec_code);
  ~Block() override;

  void Accept(Visitor &visitor) override;

public:
  ExecCode *exec_code;
};
