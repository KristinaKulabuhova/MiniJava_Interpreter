#pragma once

#include "MainElements/Class.h"

class ClassDeclarationList
{
public:
  ClassDeclarationList() = default;
  ~ClassDeclarationList() = default;
  
  void addClass(Class *new_class);

  std::vector<Class *> GetClasses() const;

private:
  std::vector<Class *> classes_;
};
