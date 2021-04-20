#ifndef PARSEREXAMPLE_BASEMETHOD_H
#define PARSEREXAMPLE_BASEMETHOD_H

#include "Visitors/Visitor.h"
#include "ExecBlocks/ExecCode.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "SubsidiaryClasses/Formals.h"
#include "types/StVariable.h"
#include <memory>

class MethodDeclaration : BaseExecBlock {
  public:
    int Accept(Visitor& visitor) override;
    ~MethodDeclaration() override = default;
    MethodDeclaration(std::string name, Formals* arguments, VarTypeStr return_type, ExecCode* exec_code);
    std::string getName() const;
    std::shared_ptr<Formals> getFormals() const;
    VarTypeStr getType() const;
    std::shared_ptr<ExecCode> getCode() const;

    std::string name_;
    std::shared_ptr<Formals> arguments_;
    VarTypeStr return_type_;
    std::shared_ptr<ExecCode> exec_code_;
};

#endif //PARSEREXAMPLE_BASEMETHOD_H