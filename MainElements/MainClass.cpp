#include "MainClass.h"

MainClass::MainClass(std::string name, ExecCode *exec_code) : Class(std::move(name), "")
{
    auto *decl_list = new DeclarationList();
    decl_list->addDecl(new MethodDeclaration("main", nullptr, new VarTypeStr(new SimpleType(2, "void"), false), exec_code));
    initialize(decl_list);
}

void MainClass::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
