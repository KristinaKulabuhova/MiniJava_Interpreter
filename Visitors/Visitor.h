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

struct VarTypeStr {
    VarType type;
    bool array{false};
};

class Visitor {
  public:
    virtual int Visit(AtExpr* expression) = 0;
    virtual int Visit(FieldExpr* expression) = 0;
    virtual int Visit(NewArrExpr* expression) = 0;
    virtual int Visit(NewCustomVarExpr* expression) = 0;

    virtual int Visit(AndExpr* expression) = 0;
    virtual int Visit(NotExpr* expression) = 0;
    virtual int Visit(OrExpr* expression) = 0;

    virtual int Visit(AddExpr* expression) = 0;
    virtual int Visit(ModExpr* expression) = 0;
    virtual int Visit(MulExpr* expression) = 0;
    virtual int Visit(DivExpr* expression) = 0;
    virtual int Visit(SubtractExpr* expression) = 0;

    virtual int Visit(EqExpr* expression) = 0;
    virtual int Visit(GEqExpr* expression) = 0;
    virtual int Visit(Greater* expression) = 0;
    virtual int Visit(NEqExpr* expression) = 0;
    virtual int Visit(LEqExpr* expression) = 0;
    virtual int Visit(LessExpr* expression) = 0;  
    
    virtual int Visit(IdentExpr* expression) = 0;
    virtual int Visit(LengthExpr* expression) = 0;
    virtual int Visit(VarExpr* expression) = 0;
    virtual int Visit(NumExpr* expression) = 0;
    virtual int Visit(ThisExpr* expression) = 0;
    
    virtual int Visit(FalseExpr* expression) = 0;
    virtual int Visit(TrueExpr* expression) = 0;

    virtual int Visit(Class* expression) = 0;
    virtual int Visit(MainClass* expression) = 0;
    virtual int Visit(MethodInvocation* expression) = 0;

    virtual int Visit(For* expression) = 0;
    virtual int Visit(If* branching) = 0;
    virtual int Visit(While* expression) = 0;

    virtual int Visit(Lvalue* expression) = 0;
    virtual int Visit(MethodDeclaration* expression) = 0;
    virtual int Visit(Println* expression) = 0;
    virtual int Visit(Return* expression) = 0;
    virtual int Visit(VariableDeclaration* expression) = 0;
    virtual int Visit(AssertExpr* expression) = 0;
    virtual int Visit(Assignment* assignment) = 0;
    virtual int Visit(Block* expression) = 0;
    virtual int Visit(ExecCode* expression) = 0;  

    virtual int Visit(Program* program) = 0;
};

#endif //PARSEREXAMPLE_VISITOR_H
