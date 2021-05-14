#pragma once

#include "BaseElements/BaseExecBlock.h"
#include "ExecBlocks/ExecCode.h"

class Block : public BaseExecBlock
{
public:
  Block(ExecCode *exec_code, yy::location loc);
  ~Block() override = default;

  void Accept(Visitor &visitor) override;

  ExecCode* GetExecCode() const;

private:
  ExecCode *exec_code;
};
