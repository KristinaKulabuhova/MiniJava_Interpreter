#include "ExecCode.h"

ExecCode::~ExecCode() {
    for (auto& line : program_lines_) {
        delete line;
    }
}

int ExecCode::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

void ExecCode::addBaseBlock(BaseExecBlock *line) {
    program_lines_.emplace_back(line);
}

ExecCode::ExecCode(BaseExecBlock *line) {
    program_lines_.emplace_back(line)
}
