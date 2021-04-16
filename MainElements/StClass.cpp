#include "MainElements/Class.h"

#include <utility>

Class::Class(std::string name, std::string parent_class) :
name_(std::move(name)), parent_class_(std::move(parent_class)) {}

void Class::initialize(DeclarationList *decl_list) {
    for (std::variant<MethodDeclaration*, VariableDeclaration*>& declaration : decl_list->declarations) {
        if (declaration.index() == 0) {
            addMethod(std::get<MethodDeclaration*>(declaration));
        } else {
            addVariable(std::get<VariableDeclaration*>(declaration));
        }
    }
    delete decl_list;
}

void Class::addMethod(MethodDeclaration *declaration) {
    methods_.emplace_back(declaration);
}

void Class::addVariable(VariableDeclaration *declaration) {
    variables_.emplace_back(declaration);
}

int Class::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}

Class::~Class() {
    for (VariableDeclaration* declaration : variables_) {
        delete declaration;
    }
    for (MethodDeclaration* declaration : methods_) {
        delete declaration;
    }
}
