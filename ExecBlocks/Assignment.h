#ifndef PARSEREXAMPLE_ASSIGNMENT_H
#define PARSEREXAMPLE_ASSIGNMENT_H

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock {
  public:
    BaseExpr* to;
    BaseExpr* from;
    Assignment(BaseExpr* to, BaseExpr* from);
    int Accept(Visitor& visitor) override;
    ~Assignment() override;
};


#endif //PARSEREXAMPLE_ASSIGNMENT_H
