#include "SubsidiaryClasses/DeclarationList.h"

void DeclarationList::addDecl(const std::variant<MethodDeclaration *, VariableDeclaration *> &declaration) {
    declarations.push_back(declaration);
}
