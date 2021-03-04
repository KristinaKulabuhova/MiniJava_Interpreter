#ifndef PASCAL_CLASSDECLARATIONLIST_H
#define PASCAL_CLASSDECLARATIONLIST_H

#include "MainElements/Class.h"

class ClassDeclarationList {
  public:
    std::vector<Class*> classes;
    void addClass(Class* new_class);
};


#endif //PASCAL_CLASSDECLARATIONLIST_H
