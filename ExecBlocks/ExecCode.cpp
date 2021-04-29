#include "ExecCode.h"

ExecCode::ExecCode(BaseExecBlock *line)
{
    program_lines_.emplace_back(line);
}

ExecCode::~ExecCode()
{
    for (auto &line : program_lines_)
    {
        delete line;
    }
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