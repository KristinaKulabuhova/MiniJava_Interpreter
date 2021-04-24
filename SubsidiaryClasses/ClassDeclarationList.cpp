#include "ClassDeclarationList.h"

void ClassDeclarationList::addClass(Class *new_class)
{
    classes.emplace_back(new_class);
}
