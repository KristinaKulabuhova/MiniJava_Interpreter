#ifndef PARSEREXAMPLE_BASEMETHOD_H
#define PARSEREXAMPLE_BASEMETHOD_H

#include "Visitors/Visitor.h"
#include "ExecBlocks/ExecCode.h"
#include "ExecBlocks/VariableDeclaration.h"

class MethodDeclaration {
  public:
    virtual void Accept(Visitor& visitor);
    virtual ~MethodDeclaration() = default;
    MethodDeclaration(std::string name, std::vector<VariableDeclaration*> arguments, VarType return_type, ExecCode* exec_code);
  private:
    std::string name_;
    std::vector<VariableDeclaration*> arguments_;
    VarType return_type_;
    ExecCode* exec_code_;
};

#endif //PARSEREXAMPLE_BASEMETHOD_H