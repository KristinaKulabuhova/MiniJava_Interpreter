#pragma once
#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock {
  public:
    BaseExpr* to;
    BaseExpr* from;
    Assignment(BaseExpr* to, BaseExpr* from);
    void Accept(Visitor& visitor) override;
    ~Assignment() override;
};


