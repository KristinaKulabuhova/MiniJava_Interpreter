#ifndef PARSEREXAMPLE_BASEMETHOD_H
#define PARSEREXAMPLE_BASEMETHOD_H

#include "Visitors/Visitor.h"
#include "ExecBlocks/ExecCode.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "SubsidiaryClasses/Formals.h"

class MethodDeclaration : BaseExecBlock {
  public:
    int Accept(Visitor& visitor) override;
    ~MethodDeclaration() override = default;
    MethodDeclaration(std::string name, Formals* arguments, VarTypeStr return_type, ExecCode* exec_code);
  private:
    std::string name_;
    Formals* arguments_;
    VarTypeStr return_type_;
    ExecCode* exec_code_;
};

#endif //PARSEREXAMPLE_BASEMETHOD_H