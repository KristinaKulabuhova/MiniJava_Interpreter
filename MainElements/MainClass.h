#ifndef PARSEREXAMPLE_MAINCLASS_H
#define PARSEREXAMPLE_MAINCLASS_H

#include "Visitors/Visitor.h"
#include "Class.h"
#include "ExecBlocks/MethodDeclaration.h"

class MainClass : public Class {
  public:
    int Accept(Visitor& visitor) override;
    ~MainClass() override = default;
    MainClass(std::string name, ExecCode* exec_code);
};

#endif //PARSEREXAMPLE_MAINCLASS_H