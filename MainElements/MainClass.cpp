#include "MainClass.h"

MainClass::MainClass(std::string name, ExecCode* exec_code) :
Class(std::move(name), nullptr, {}, {new MethodDeclaration("main", {}, void_t, exec_code)}) {}