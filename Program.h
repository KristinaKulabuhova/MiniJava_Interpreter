#pragma once

#include "SubsidiaryClasses/ClassDeclarationList.h"
#include "MainElements/MainClass.h"
#include "ExecBlocks/ExecCode.h"

class Program {
  public:
    MainClass* main_class;
    ClassDeclarationList* class_decl_list;
    Program(MainClass* main_class, ClassDeclarationList* class_decl_list);
    void Accept(Visitor& visitor);
    ~Program();
};


