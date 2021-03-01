#ifndef PARSEREXAMPLE_VARIABLE_H
#define PARSEREXAMPLE_VARIABLE_H

#include "Visitors/Visitor.h"

class Variable {
  public:
    virtual void Accept(Visitor& visitor);
    virtual ~BaseClass() = default;
    Variable(VarType type, std::string name, int value = 0);

  private:
    VarType type_;
    std::string name_;
    int value_;
};

#endif //PARSEREXAMPLE_VARIABLE_H