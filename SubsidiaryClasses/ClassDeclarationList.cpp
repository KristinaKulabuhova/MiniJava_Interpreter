#include "ClassDeclarationList.h"

ClassDeclarationList::ClassDeclarationList(yy::location loc) {
    location_ = loc;
}

void ClassDeclarationList::addClass(Class *new_class)
{
    classes_.emplace_back(new_class);
}

std::vector<Class *> ClassDeclarationList::GetClasses() const {
    return classes_;
}