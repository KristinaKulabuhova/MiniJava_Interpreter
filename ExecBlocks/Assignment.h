#ifndef PARSEREXAMPLE_ASSIGNMENT_H
#define PARSEREXAMPLE_ASSIGNMENT_H

#include "ExecBlocks/Lvalue.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock {
  public:
    Lvalue* var;
    BaseExpr* expression;
    Assignment(Lvalue* var, BaseExpr* expression);
    int Accept(Visitor& visitor) override;
    ~Assignment() override;
};


#endif //PARSEREXAMPLE_ASSIGNMENT_H
