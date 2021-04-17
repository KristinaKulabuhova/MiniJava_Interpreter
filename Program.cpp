#include "Program.h"

Program::~Program() {
    delete main_class;
    for (auto& p_class : class_decl_list->classes) {
        delete p_class;
    }
}

Program::Program(MainClass *main_class, ClassDeclarationList *class_decl_list) :
main_class(main_class), class_decl_list(class_decl_list) {}

int Program::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
