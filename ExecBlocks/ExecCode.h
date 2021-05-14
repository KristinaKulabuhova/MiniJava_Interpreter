#pragma once

#include "BaseElements/BaseExecBlock.h"

#include <vector>

class ExecCode : public BaseExecBlock
{
public:
  ExecCode( yy::location loc);
  explicit ExecCode(BaseExecBlock *line, yy::location loc);
  ~ExecCode() override = default;

  void addBaseBlock(BaseExecBlock *line);
  void Accept(Visitor &visitor) override;

  std::vector<BaseExecBlock *> GetProgramLines() const;

private:
  std::vector<BaseExecBlock *> program_lines_;
};
