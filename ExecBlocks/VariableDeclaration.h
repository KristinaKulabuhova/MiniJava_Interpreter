#pragma once

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExecBlock.h"
#include "Expressions/VarType.h"

class VariableDeclaration : public BaseExecBlock {
  public:
    virtual void Accept(Visitor& visitor) override;
    virtual ~VariableDeclaration() = default;
    VariableDeclaration(VarTypeStr* type, std::string name, int value = 0);
    VarTypeStr* getType() const;
    std::string getName() const;
    int getValue() const;

    VarTypeStr* type_;
    std::string name_;
    int value_;
};
