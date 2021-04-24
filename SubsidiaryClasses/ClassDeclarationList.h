#pragma once

#include "MainElements/Class.h"

class ClassDeclarationList
{
public:
  ClassDeclarationList() = default;
  ~ClassDeclarationList() = default;
  
  void addClass(Class *new_class);

public:
  std::vector<Class *> classes;
};
