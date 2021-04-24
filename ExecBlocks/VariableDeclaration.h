#pragma once

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExecBlock.h"
#include "Expressions/VarType.h"

class VariableDeclaration : public BaseExecBlock
{
public:
  VariableDeclaration(VarTypeStr *type, std::string name, int value = 0);
  virtual ~VariableDeclaration() = default;

  VarTypeStr *getType() const;
  std::string getName() const;
  int getValue() const;

  virtual void Accept(Visitor &visitor) override;

public:
  VarTypeStr *type_;
  std::string name_;
  int value_;
};
