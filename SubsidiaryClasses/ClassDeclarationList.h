#pragma once

#include "MainElements/Class.h"

class ClassDeclarationList {
  public:
    std::vector<Class*> classes;
    void addClass(Class* new_class);
};

