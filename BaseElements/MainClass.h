#ifndef PARSEREXAMPLE_MAINCLASS_H
#define PARSEREXAMPLE_MAINCLASS_H

#include "Visitors/Visitor.h"
#include "BaseExecBloch.h"
#include "Class.h"

class MainClass : public Class {
  public:
    virtual ~MainClass() = default;
    MainClass(std::string name, ExecCode* exec_code);
};

#endif //PARSEREXAMPLE_MAINCLASS_H