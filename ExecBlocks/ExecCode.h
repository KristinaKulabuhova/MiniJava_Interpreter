#pragma once

#include "BaseElements/BaseExecBlock.h"

#include <vector>

class ExecCode : public BaseExecBlock
{
public:
  ExecCode() = default;
  explicit ExecCode(BaseExecBlock *line);
  ~ExecCode() override;

  void addBaseBlock(BaseExecBlock *line);
  void Accept(Visitor &visitor) override;

public:
  std::vector<BaseExecBlock *> program_lines_;
};
