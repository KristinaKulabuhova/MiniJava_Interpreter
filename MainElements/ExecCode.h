#ifndef PARSEREXAMPLE_EXECCODE_H
#define PARSEREXAMPLE_EXECCODE_H

#include "BaseElements/BaseExecBlock.h"

#include <vector>

class ExecCode : public BaseExecBlock {
  public:
    std::vector<BaseExecBlock*> program_lines_;
    explicit ExecCode(BaseExecBlock* line);
    void Accept(Visitor& visitor) override;
    ~ExecCode() override;
    void addBaseBlock(BaseExecBlock* line);
};


#endif //PARSEREXAMPLE_EXECCODE_H
