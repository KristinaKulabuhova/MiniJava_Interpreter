#include "ExecCode.h"

ExecCode::ExecCode(yy::location loc) : BaseExecBlock(loc)
{
}

ExecCode::ExecCode(BaseExecBlock *line, yy::location loc) : BaseExecBlock(loc)
{
    program_lines_.emplace_back(line);
}

void ExecCode::addBaseBlock(BaseExecBlock *line)
{
    program_lines_.emplace_back(line);
}

void ExecCode::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

std::vector<BaseExecBlock *> ExecCode::GetProgramLines() const {
    return program_lines_;
}