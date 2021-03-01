#include "Methods.h"

Method::Method(std::string name, std::vector<Variable*> arguments, VarType return_type, ExecCode* exec_code) :
name_(std::move(name)), arguments_(std::move(arguments)), return_type_(return_type), exec_code_(exec_code) {}