#include "MainClass.h"

MainClass(std::string name, ExecCode* exec_code) :
Class(std::move(name), nullptr, {}, {new Method("main", {}, void_t, exec_code)}) {}