#ifndef PARSEREXAMPLE_PROGRAM_H
#define PARSEREXAMPLE_PROGRAM_H

#include "VarDeclList/VarDeclList.h"
#include "MainElements/ExecCode.h"

class Program {
  public:
    std::string program_name;
    std::vector<VarDeclList*> var_declarations;
    ExecCode* executable_code;
    Program(std::string program_name, std::vector<VarDeclList*> var_declarations, ExecCode* executable_code);
    ~Program();
};


#endif //PARSEREXAMPLE_PROGRAM_H
