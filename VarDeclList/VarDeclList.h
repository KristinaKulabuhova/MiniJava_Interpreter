#ifndef PARSEREXAMPLE_VARDECLLIST_H
#define PARSEREXAMPLE_VARDECLLIST_H

#include <vector>
#include <string>
#include <stdexcept>

class UnknownTypeError : public std::runtime_error {
  public:
    explicit UnknownTypeError(const std::string& type) :
            std::runtime_error("Unknown type " + type + ".") {};
};

enum var_type {
    integer,
    string,
    unknown
};

class VarDeclList {
  public:
    std::vector<std::string> var_names;
    var_type type;
    VarDeclList(const std::string& var_name, const std::string& type);
    ~VarDeclList() = default;
    void addVar(const std::string& var_name);
};


#endif //PARSEREXAMPLE_VARDECLLIST_H
