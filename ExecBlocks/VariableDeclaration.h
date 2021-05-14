#pragma once

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExecBlock.h"
#include "Expressions/VarType.h"

class VariableDeclaration : public BaseExecBlock
{
public:
  VariableDeclaration(VarTypeStr *type, std::string name, yy::location loc, int value = 0);
  ~VariableDeclaration() override = default;

  VarTypeStr *GetType() const;
  std::string GetName() const;
  int GetValue() const;

  virtual void Accept(Visitor &visitor) override;

private:
  VarTypeStr *type_;
  std::string name_;
  int value_;
};
