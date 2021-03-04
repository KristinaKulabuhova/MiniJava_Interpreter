#ifndef PASCAL_FORMALS_H
#define PASCAL_FORMALS_H

#include "vector"
#include "Visitors/Visitor.h"

class Formals {
  public:
    std::vector<std::pair<VarType, std::string>> variables;
    Formals(VarType type, std::string name);
    void addVar(VarType type, std::string name);
};


#endif //PASCAL_FORMALS_H
