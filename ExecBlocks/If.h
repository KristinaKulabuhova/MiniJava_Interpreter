#ifndef PARSEREXAMPLE_IF_H
#define PARSEREXAMPLE_IF_H

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

class If : public BaseExecBlock {
  public:
    BaseExpr* statement;
    BaseExecBlock* true_branch;
    BaseExecBlock* false_branch;
    If(BaseExpr* statement, BaseExecBlock* true_branch, BaseExecBlock* false_branch = nullptr);
    int Accept(Visitor& visitor) override;
    ~If() override;
};


#endif //PARSEREXAMPLE_IF_H
