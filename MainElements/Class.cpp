#include "MainElements/Class.h"

#include <utility>

Class::Class(std::string name, std::string parent_class, yy::location loc) : BaseDeclaration(loc)
{
    name_ = std::move(name); 
    parent_class_ = std::move(parent_class);
}

void Class::initialize(DeclarationList *decl_list)
{
    for (auto &declaration : decl_list->GetDeclarations())
    {
        if (declaration.index() == 0)
        {
            addMethod(std::get<MethodDeclaration *>(declaration));
        }
        else
        {
            addVariable(std::get<VariableDeclaration *>(declaration));
        }
    }
    delete decl_list;
}

void Class::addMethod(MethodDeclaration *declaration)
{
    methods_.emplace_back(declaration);
}

void Class::addVariable(VariableDeclaration *declaration)
{
    variables_.emplace_back(declaration);
}

void Class::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

std::string Class::GetName() const
{
    return name_;
}

std::string Class::GetParent() const
{
    return parent_class_;
}

std::vector<VariableDeclaration *> Class::GetVariable() const
{
    return variables_;
}

std::vector<MethodDeclaration *> Class::GetMethods() const
{
    return methods_;
}
