#pragma once

#include "Visitors/Visitor.h"
#include "ExecBlocks/ExecCode.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "SubsidiaryClasses/Formals.h"
#include "symbols/StVariable.h"
#include <Expressions/VarType.h>
#include <memory>

class MethodDeclaration : public BaseExecBlock
{
public:
  MethodDeclaration(std::string name, Formals *arguments, VarTypeStr *return_type, ExecCode *exec_code, yy::location loc);
  ~MethodDeclaration() override = default;

  std::string GetName() const;
  Formals* GetFormals() const;
  VarTypeStr *GetType() const;
  ExecCode* GetCode() const;

  void Accept(Visitor &visitor) override;

private:
  std::string name_;
  Formals* arguments_;
  VarTypeStr *return_type_;
  ExecCode* exec_code_;
};
