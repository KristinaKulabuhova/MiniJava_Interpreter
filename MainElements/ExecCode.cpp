#include "ExecCode.h"

ExecCode::ExecCode(BaseExecBlock* line) {
    program_lines_.push_back(line);
}

ExecCode::~ExecCode() {
    for (auto& line : program_lines_) {
        delete line;
    }
}

void ExecCode::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

void ExecCode::addBaseBlock(BaseExecBlock *line) {
    program_lines_.push_back(line);
}
