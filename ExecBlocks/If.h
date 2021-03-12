#ifndef PARSEREXAMPLE_IF_H
#define PARSEREXAMPLE_IF_H

#include "BaseElements/BaseExpr.h"
#include "ExecCode.h"

class If : public BaseExecBlock {
  public:
    BaseExpr* statement;
    ExecCode* true_branch;
    ExecCode* false_branch;
    If(BaseExpr* statement, ExecCode* true_branch, ExecCode* false_branch);
    int Accept(Visitor& visitor) override;
    ~If() override;
};


#endif //PARSEREXAMPLE_IF_H
