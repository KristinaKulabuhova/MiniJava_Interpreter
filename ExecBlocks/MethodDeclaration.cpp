#include "ExecBlocks/MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(std::string name, Formals *arguments, VarTypeStr *return_type, ExecCode *exec_code) : name_(std::move(name)), arguments_(arguments), return_type_(return_type), exec_code_(exec_code) {}

void MethodDeclaration::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

std::string MethodDeclaration::GetName() const
{
    return name_;
}

std::shared_ptr<Formals> MethodDeclaration::GetFormals() const
{
    return arguments_;
}

VarTypeStr *MethodDeclaration::GetType() const
{
    return return_type_;
}

std::shared_ptr<ExecCode> MethodDeclaration::GetCode() const
{
    return exec_code_;
}
