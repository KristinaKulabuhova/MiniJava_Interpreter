#include "Variable.h"

Variable(VarType type, std::string name, int value = 0) : 
type_(type), name_(std::move(name)), value_(value) {}