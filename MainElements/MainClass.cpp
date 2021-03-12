#include "MainClass.h"

MainClass::MainClass(std::string name, ExecCode* exec_code) :
Class(std::move(name), nullptr) {
    auto* decl_list = new DeclarationList();
    decl_list->addDecl(new MethodDeclaration("main", {}, void_t, exec_code));
    initialize(decl_list);
}

int MainClass::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
