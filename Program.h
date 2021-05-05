#pragma once

#include "SubsidiaryClasses/ClassDeclarationList.h"
#include "MainElements/MainClass.h"
#include "ExecBlocks/ExecCode.h"

class Program
{
public:
  Program(MainClass *main_class, ClassDeclarationList *class_decl_list);
  ~Program() = default;

  void Accept(Visitor &visitor);

public:
  MainClass *main_class;
  ClassDeclarationList *class_decl_list;
};
