#ifndef PARSEREXAMPLE_BASECLASS_H
#define PARSEREXAMPLE_BASECLASS_H

#include "Visitors/Visitor.h"
#include "Variable.h"

class Class {
  public:
    virtual void Accept(Visitor& visitor);
    virtual ~BaseClass() = default;
    Class(std::string name, BaseClass* parent_class, std::vector<Variable*> variables, std::vector<BaseMethod*> methods); 
    void addField(Variable* variable);
    void addMethodMe(Method* method);

  protected:
    std::string name_;
    Class* parent_class_;
    std::vector<Variable*> variables_;
    std::vector<Method*> methods_;
};

#endif //PARSEREXAMPLE_BASECLASS_H