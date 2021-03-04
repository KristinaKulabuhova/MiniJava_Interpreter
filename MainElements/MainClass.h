#ifndef PARSEREXAMPLE_MAINCLASS_H
#define PARSEREXAMPLE_MAINCLASS_H

#include "Visitors/Visitor.h"
#include "Class.h"
#include "MethodDeclaration.h"

class MainClass : public Class {
  public:
    ~MainClass() override = default;
    MainClass(std::string name, ExecCode* exec_code);
};

#endif //PARSEREXAMPLE_MAINCLASS_H