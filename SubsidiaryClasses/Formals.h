#ifndef PASCAL_FORMALS_H
#define PASCAL_FORMALS_H

#include "vector"
#include "Visitors/Visitor.h"

class Formals {
  public:
    std::vector<std::pair<VarTypeStr, std::string>> variables;
    Formals(VarTypeStr type, std::string name);
    void addVar(VarTypeStr type, std::string name);
    int Accept(Visitor& visitor);
};


#endif //PASCAL_FORMALS_H
