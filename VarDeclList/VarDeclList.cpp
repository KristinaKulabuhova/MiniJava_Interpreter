#include "VarDeclList.h"

VarDeclList::VarDeclList(const std::string& var_name, const std::string& type_str) {
    if (type_str == "string") {
        type = string;
    } else if (type_str == "integer") {
        type = integer;
    } else {
        throw UnknownTypeError(type_str);
    }
    var_names.push_back(var_name);
}

void VarDeclList::addVar(const std::string &var_name) {
    var_names.push_back(var_name);
}
