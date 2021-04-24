#pragma once 

#include "Visitor.h"
#include "AllIncludes.h"
#include <tuple>

#include <variant>
#include <map>
#include <set>
#include <memory>
#include <variant>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <iostream>

class Interpreter : public Visitor {
  public:
    void Visit(AtExpr* expression) override;
    void Visit(FieldExpr* expression) override;
    void Visit(NewArrExpr* expression) override;
    void Visit(NewCustomVarExpr* expression) override;

    void Visit(AndExpr* expression) override;
    void Visit(NotExpr* expression) override;
    void Visit(OrExpr* expression) override;

    void Visit(AddExpr* expression) override;
    void Visit(ModExpr* expression) override;
    void Visit(MulExpr* expression) override;
    void Visit(DivExpr* expression) override;
    void Visit(SubtractExpr* expression) override;

    void Visit(EqExpr* expression) override;
    void Visit(GEqExpr* expression) override;
    void Visit(GreaterExpr* expression) override;
    void Visit(NEqExpr* expression) override;
    void Visit(LEqExpr* expression) override;
    void Visit(LessExpr* expression) override;  
    
    void Visit(IdentExpr* expression) override;
    void Visit(LengthExpr* expression) override;
    void Visit(NumExpr* expression) override;
    
    void Visit(FalseExpr* expression) override;
    void Visit(TrueExpr* expression) override;

    void Visit(Class* expression) override;
    void Visit(MainClass* expression) override;
    void Visit(MethodInvocation* expression) override;

    void Visit(If* branching) override;
    void Visit(While* expression) override;

    void Visit(MethodDeclaration* expression) override;
    void Visit(Println* expression) override;
    void Visit(Return* expression) override;
    void Visit(VariableDeclaration* expression) override;
    void Visit(AssertExpr* expression) override;
    void Visit(Assignment* assignment) override;
    void Visit(Block* expression) override;
    void Visit(ExecCode* expression) override; 
    void Visit(Formals* formals) override;

    void Visit(Program* program) override;

  private:
    std::map<std::string, int> variables_;
    bool is_tos_expr_;
    int tos_value_;
    std::string curr_name_;

    void SetTosValue(int value);
    void UnsetTosValue();

};
