#include "Class.h"

Class(std::string name, BaseClass* parent_class, std::vector<Variable*> variables, std::vector<BaseMethod*> methods) : 
name_(std::name), parent_class_(parent_class), variables_(variables), methods_(method) {}

void addField(Variable* variable) {
    variables_.emplace_back(variable);
}

void addMethodMe(Method* method) {
    methods_.emplace_back(method);
}
