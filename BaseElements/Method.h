#ifndef PARSEREXAMPLE_BASEMETHOD_H
#define PARSEREXAMPLE_BASEMETHOD_H

#include "Visitors/Visitor.h"
#include "BaseExecBloch.h"
#include "MainElements/ExecCode.h"

class Method {
  public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~BaseMethod() = default;
    Method(std::string name, std::vector<Variable*> arguments, VarType return_type, ExecCode* exec_code);
  private:
    std::string name_;
    std::vector<Variable*> arguments_;
    VarType return_type_;
    ExecCode* exec_code_;
};

#endif //PARSEREXAMPLE_BASEMETHOD_H