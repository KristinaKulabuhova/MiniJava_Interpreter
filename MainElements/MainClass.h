#pragma once

#include "Visitors/Visitor.h"
#include "Class.h"
#include "ExecBlocks/MethodDeclaration.h"

class MainClass : public Class {
  public:
    void Accept(Visitor& visitor) override;
    ~MainClass() override = default;
    MainClass(std::string name, ExecCode* exec_code);
};

