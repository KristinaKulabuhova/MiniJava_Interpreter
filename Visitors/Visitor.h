#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include "ForwardDeclarations.h"

#include <variant>
#include <string>

enum VarType {
  int_t,
  bool_t,
  void_t,
  custom_t
};

class Visitor {
  public:
    virtual int Visit(AddExpr* expression) = 0;
    virtual int Visit(DivExpr* expression) = 0;
    virtual int Visit(ModExpr* expression) = 0;
    virtual int Visit(MulExpr* expression) = 0;
    virtual int Visit(SubtractExpr* expression) = 0;
    virtual int Visit(IdentExpr* expression) = 0;
    virtual int Visit(ConstExpr* expression) = 0;

    virtual int Visit(LessExpr* expression) = 0;
    virtual int Visit(GreaterExpr* expression) = 0;
    virtual int Visit(LEqExpr* expression) = 0;
    virtual int Visit(GEqExpr* expression) = 0;
    virtual int Visit(EqExpr* expression) = 0;
    virtual int Visit(NEqExpr* expression) = 0;
    virtual int Visit(AndExpr* expression) = 0;
    virtual int Visit(OrExpr* expression) = 0;
    virtual int Visit(NotExpr* expression) = 0;
    virtual int Visit(LengthExpr* expression) = 0;

    virtual int Visit(FalseExpr* expression) = 0;
    virtual int Visit(TrueExpr* expression) = 0;

    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(ExecCode* code) = 0;
    virtual void Visit(If* branching) = 0;
    virtual void Visit(While* while_cycle) = 0;
    virtual void Visit(For* for_cycle) = 0;
    virtual void Visit(Read* read_module) = 0;
    virtual void Visit(Write* write_module) = 0;
};

#endif //PARSEREXAMPLE_VISITOR_H
