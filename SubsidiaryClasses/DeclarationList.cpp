#include "SubsidiaryClasses/DeclarationList.h"

DeclarationList::DeclarationList(yy::location loc) {
    location_ = loc;
}

void DeclarationList::addDecl(BaseExecBlock *declaration)
{
    auto method_decl = dynamic_cast<MethodDeclaration *>(declaration);
    auto var_decl = dynamic_cast<VariableDeclaration *>(declaration);

    if (method_decl)
    {
        declarations.push_back(method_decl);
    }
    else
    {
        declarations.push_back(var_decl);
    }
}

std::vector<std::variant<MethodDeclaration *, VariableDeclaration *>> DeclarationList::GetDeclarations() const
{
    return declarations;
}
