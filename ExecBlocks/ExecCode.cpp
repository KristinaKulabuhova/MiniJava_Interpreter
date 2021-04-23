#include "ExecCode.h"

ExecCode::~ExecCode() {
    for (auto& line : program_lines_) {
        delete line;
    }
}

void ExecCode::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

void ExecCode::addBaseBlock(BaseExecBlock *line) {
    program_lines_.emplace_back(line);
}

ExecCode::ExecCode(BaseExecBlock *line) {
    program_lines_.emplace_back(line);
}
