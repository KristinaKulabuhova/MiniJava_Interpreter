#ifndef PARSEREXAMPLE_WHILE_H
#define PARSEREXAMPLE_WHILE_H

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock {
  public:
    BaseExpr* statement;
    BaseExecBlock* cycle_body;
    While(BaseExpr* statement, BaseExecBlock* cycle_body);
    int Accept(Visitor& visitor) override;
    ~While() override;
};


#endif //PARSEREXAMPLE_WHILE_H
