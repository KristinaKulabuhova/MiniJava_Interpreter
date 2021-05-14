#pragma once

#include "MainElements/Class.h"

class ClassDeclarationList
{
public:
  ClassDeclarationList(yy::location loc);
  ~ClassDeclarationList() = default;
  
  void addClass(Class *new_class);

  std::vector<Class *> GetClasses() const;

private:
  std::vector<Class *> classes_;
  yy::location location_;
};
