#ifndef PARSEREXAMPLE_ASSIGNMENT_H
#define PARSEREXAMPLE_ASSIGNMENT_H

#include "BaseElements/BaseExpr.h"
#include "BaseElements/BaseExecBlock.h"

#include "string"

class Assignment : public BaseExecBlock {
  public:
    std::string var_name_;
    BaseExpr* expression;
    Assignment(std::string var_name_, BaseExpr* expression);
    void Accept(Visitor& visitor) override;
    ~Assignment() override;
};


#endif //PARSEREXAMPLE_ASSIGNMENT_H
