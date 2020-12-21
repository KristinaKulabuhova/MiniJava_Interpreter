#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include "ForwardDeclarations.h"

//class BaseExpr;
//class AddExpr;
//class DivExpr;
//class ModExpr;
//class MulExpr;
//class SubtractExpr;
//class IdentExpr;
//class Assignment;
//class ExecCode;
//class While;
//class For;
//class LessExpr;
//class GreaterExpr;
//class LeqExpr;
//class GeqExpr;
//class EqExpr;
//class NEqExpr;
//class AndExpr;
//class OrExpr;
//class NotExpr;

#include <variant>
#include <string>

using var_t = std::variant<int, std::string>;

class Visitor {
  public:
    virtual var_t Visit(AddExpr* expression) = 0;
    virtual var_t Visit(DivExpr* expression) = 0;
    virtual var_t Visit(ModExpr* expression) = 0;
    virtual var_t Visit(MulExpr* expression) = 0;
    virtual var_t Visit(SubtractExpr* expression) = 0;
    virtual var_t Visit(IdentExpr* expression) = 0;
    virtual var_t Visit(ConstExpr* expression) = 0;

    virtual var_t Visit(LessExpr* expression) = 0;
    virtual var_t Visit(GreaterExpr* expression) = 0;
    virtual var_t Visit(LeqExpr* expression) = 0;
    virtual var_t Visit(GeqExpr* expression) = 0;
    virtual var_t Visit(EqExpr* expression) = 0;
    virtual var_t Visit(NEqExpr* expression) = 0;
    virtual var_t Visit(AndExpr* expression) = 0;
    virtual var_t Visit(OrExpr* expression) = 0;
    virtual var_t Visit(NotExpr* expression) = 0;

    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(ExecCode* code) = 0;
    virtual void Visit(If* branching) = 0;
    virtual void Visit(While* while_cycle) = 0;
    virtual void Visit(For* for_cycle) = 0;
    virtual void Visit(Read* read_module) = 0;
    virtual void Visit(Write* write_module) = 0;
};

#endif //PARSEREXAMPLE_VISITOR_H
