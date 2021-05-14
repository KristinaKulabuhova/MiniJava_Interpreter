#include "MainClass.h"

MainClass::MainClass(std::string name, ExecCode *exec_code, yy::location loc) : Class(std::move(name), "", loc)
{
    auto *decl_list = new DeclarationList(loc);
    decl_list->addDecl(new MethodDeclaration("main", nullptr, new VarTypeStr(new SimpleType(2, "void"), false), exec_code, loc));
    initialize(decl_list);
}

void MainClass::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
