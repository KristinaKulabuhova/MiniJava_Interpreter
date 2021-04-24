#pragma once
#include "BaseElements/BaseExpr.h"
#include "Expressions/IdentExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock {
  public:
    Assignment(IdentExpr* to, BaseExpr* from);
    ~Assignment() override;

    void Accept(Visitor& visitor) override;

  public:
    IdentExpr* to;
    BaseExpr* from;
};
