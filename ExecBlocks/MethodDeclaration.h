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
  MethodDeclaration(std::string name, Formals *arguments, VarTypeStr *return_type, ExecCode *exec_code);
  ~MethodDeclaration() override = default;

  std::string GetName() const;
  std::shared_ptr<Formals> GetFormals() const;
  VarTypeStr *GetType() const;
  std::shared_ptr<ExecCode> GetCode() const;

  void Accept(Visitor &visitor) override;

private:
  std::string name_;
  std::shared_ptr<Formals> arguments_;
  VarTypeStr *return_type_;
  std::shared_ptr<ExecCode> exec_code_;
};
