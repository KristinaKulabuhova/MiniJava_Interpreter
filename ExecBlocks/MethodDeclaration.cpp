#include "ExecBlocks/MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(std::string name, Formals* arguments, VarTypeStr return_type, ExecCode* exec_code) :
name_(std::move(name)), arguments_(std::move(arguments)), return_type_(return_type), exec_code_(exec_code) {}

int MethodDeclaration::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
