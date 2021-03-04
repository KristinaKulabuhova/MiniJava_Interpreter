#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(std::string name, std::vector<Variable*> arguments, VarType return_type, ExecCode* exec_code) :
name_(std::move(name)), arguments_(std::move(arguments)), return_type_(return_type), exec_code_(exec_code) {}

void MethodDeclaration::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
