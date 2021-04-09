#ifndef PARSEREXAMPLE_VARIABLE_H
#define PARSEREXAMPLE_VARIABLE_H

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExecBlock.h"

class VariableDeclaration : public BaseExecBlock {
  public:
    int Accept(Visitor& visitor) override;
    ~VariableDeclaration() override = default;
    VariableDeclaration(VarTypeStr type, std::string name, int value = 0);

    VarTypeStr type_;
    std::string name_;
    int value_;
};

#endif //PARSEREXAMPLE_VARIABLE_H