#ifndef PARSEREXAMPLE_VARIABLE_H
#define PARSEREXAMPLE_VARIABLE_H

#include "Visitors/Visitor.h"
#include "BaseElements/BaseExpr.h"

class VariableDeclaration : public BaseExpr {
  public:
    virtual int Accept(Visitor& visitor) override;
    virtual ~VariableDeclaration() = default;
    VariableDeclaration(VarTypeStr type, std::string name, int value = 0);

  private:
    VarTypeStr type_;
    std::string name_;
    int value_;
};

#endif //PARSEREXAMPLE_VARIABLE_H