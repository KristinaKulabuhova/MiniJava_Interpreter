#include "ExecBlocks/MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(std::string name, Formals* arguments, VarTypeStr* return_type, ExecCode* exec_code) :
name_(std::move(name)), arguments_(arguments), return_type_(return_type), exec_code_(exec_code) {}

void MethodDeclaration::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

std::string MethodDeclaration::getName() const {
    return name_;
}

std::shared_ptr<Formals> MethodDeclaration::getFormals() const {
    return arguments_;
}

VarTypeStr* MethodDeclaration::getType() const {
    return return_type_;
}

std::shared_ptr<ExecCode> MethodDeclaration::getCode() const {
    return exec_code_;
}
