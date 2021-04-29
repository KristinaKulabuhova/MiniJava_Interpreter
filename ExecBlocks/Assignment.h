#pragma once
#include "BaseElements/BaseExpr.h"
#include "Expressions/IdentExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include <string>

class Assignment : public BaseExecBlock {
  public:
    Assignment(IdentExpr* to, BaseExpr* from);
    ~Assignment() override = default;

    void Accept(Visitor& visitor) override;

    IdentExpr* GetTo() const;
    BaseExpr* GetFrom() const;

  private:
    IdentExpr* to_;
    BaseExpr* from_;
};
