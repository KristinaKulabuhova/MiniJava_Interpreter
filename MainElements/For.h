#ifndef PARSEREXAMPLE_FOR_H
#define PARSEREXAMPLE_FOR_H

#include "ExecCode.h"
#include "BaseElements/BaseExpr.h"

#include <string>

class For : public BaseExecBlock {
  public:
    std::string var_name;
    BaseExpr* lower_bound;
    BaseExpr* upper_bound;
    ExecCode* cycle_body;
    For(std::string var_name, BaseExpr* lower_bound, BaseExpr* upper_bound, ExecCode* cycle_body);
    void Accept(Visitor& visitor) override;
    ~For() override;
};


#endif //PARSEREXAMPLE_FOR_H
