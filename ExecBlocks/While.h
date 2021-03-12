#ifndef PARSEREXAMPLE_WHILE_H
#define PARSEREXAMPLE_WHILE_H

#include "ExecCode.h"
#include "BaseElements/BaseExpr.h"

class While : public BaseExecBlock {
  public:
    BaseExpr* statement;
    ExecCode* cycle_body;
    While(BaseExpr* statement, ExecCode* cycle_body);
    int Accept(Visitor& visitor) override;
    ~While() override;
};


#endif //PARSEREXAMPLE_WHILE_H
