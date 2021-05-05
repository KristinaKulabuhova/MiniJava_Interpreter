#pragma once

#include "ForwardDeclarations.h"

#include <variant>
#include <string>
#include <stdexcept>


class MultiDeclError : public std::runtime_error {
  public:
    explicit MultiDeclError(const std::string& var_name) :
    std::runtime_error("Multiple declaration of variable \"" + var_name + "\".") {};
};

class UndefRefError : public std::runtime_error {
  public:
    explicit UndefRefError(const std::string& var_name) :
    std::runtime_error("Undefined reference to \"" + var_name + "\".") {};
};

class WrongBinaryOperandsError : public std::runtime_error {
  public:
    explicit WrongBinaryOperandsError(const std::string& operation,
                                      const std::string& first_type, const std::string& second_type) :
    std::runtime_error("Wrong operands to binary operation \""
    + operation + "\": " + first_type + "\" and \"" + second_type + "\".") {};
};

class ExpectedBoolError : public std::runtime_error {
  public:
    explicit ExpectedBoolError(const std::string& type) :
    std::runtime_error("Can't interpret type \"" + type + "\" as bool.") {};
};

class ExpectedIntError : public std::runtime_error {
  public:
    explicit ExpectedIntError(const std::string& type) :
            std::runtime_error("Can't interpret type \"" + type + "\" as integer.") {};
};


class Visitor {
  public:
    virtual void Visit(AtExpr* expression) = 0;
    virtual void Visit(FieldExpr* expression) = 0;
    virtual void Visit(NewArrExpr* expression) = 0;
    virtual void Visit(NewCustomVarExpr* expression) = 0;

    virtual void Visit(AndExpr* expression) = 0;
    virtual void Visit(NotExpr* expression) = 0;
    virtual void Visit(OrExpr* expression) = 0;

    virtual void Visit(AddExpr* expression) = 0;
    virtual void Visit(ModExpr* expression) = 0;
    virtual void Visit(MulExpr* expression) = 0;
    virtual void Visit(DivExpr* expression) = 0;
    virtual void Visit(SubtractExpr* expression) = 0;

    virtual void Visit(EqExpr* expression) = 0;
    virtual void Visit(GEqExpr* expression) = 0;
    virtual void Visit(GreaterExpr* expression) = 0;
    virtual void Visit(NEqExpr* expression) = 0;
    virtual void Visit(LEqExpr* expression) = 0;
    virtual void Visit(LessExpr* expression) = 0;  
    
    virtual void Visit(IdentExpr* expression) = 0;
    virtual void Visit(LengthExpr* expression) = 0;
    //virtual void Visit(VarExpr* expression) = 0;
    virtual void Visit(NumExpr* expression) = 0;
    
    virtual void Visit(FalseExpr* expression) = 0;
    virtual void Visit(TrueExpr* expression) = 0;

    virtual void Visit(Class* expression) = 0;
    virtual void Visit(MainClass* expression) = 0;
    virtual void Visit(MethodInvocation* expression) = 0;

    virtual void Visit(If* branching) = 0;
    virtual void Visit(While* expression) = 0;

    virtual void Visit(MethodDeclaration* expression) = 0;
    virtual void Visit(Println* expression) = 0;
    virtual void Visit(Return* expression) = 0;
    virtual void Visit(VariableDeclaration* expression) = 0;
    virtual void Visit(AssertExpr* expression) = 0;
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(Block* expression) = 0;
    virtual void Visit(ExecCode* expression) = 0;  

    virtual void Visit(Program* program) = 0;

    virtual void Visit(Formals* formals) = 0;
};

