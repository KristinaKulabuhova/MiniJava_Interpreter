#ifndef PARSEREXAMPLE_PROGRAM_H
#define PARSEREXAMPLE_PROGRAM_H

#include "SubsidiaryClasses/ClassDeclarationList.h"
#include "MainElements/MainClass.h"
#include "ExecBlocks/ExecCode.h"

class Program {
  public:
    MainClass* main_class;
    ClassDeclarationList* class_decl_list;
    Program(MainClass* main_class, ClassDeclarationList* class_decl_list);
    ~Program();
};


#endif //PARSEREXAMPLE_PROGRAM_H
