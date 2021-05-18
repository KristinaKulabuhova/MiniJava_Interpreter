#pragma once

#include "ForwardDeclarations.h"

#include <variant>
#include <iostream>
#include "parser.hh"
#include <string>
#include <stdexcept>
#include <vector>

inline std::vector<std::pair<std::string, yy::location>> all_errors;

inline void MultiDeclError(const std::string& var_name, yy::location loc) {
    all_errors.emplace_back("Multiple declaration of name \"" + var_name + "\".", loc);
}

inline void UndefRefError(const std::string& var_name, yy::location loc) {
    all_errors.emplace_back("Undefined reference to \"" + var_name + "\".", loc);
}

inline void WrongBinaryOperandsError(const std::string& operation,
                                      const std::string& first_type, const std::string& second_type, yy::location loc) {
    all_errors.emplace_back("std::make_pair(Wrong operands to binary operation \""
    + operation + "\": " + first_type + "\" and \"" + second_type + "\".", loc);
}

inline void ExpectedBoolError(const std::string& type, yy::location loc) {
    all_errors.emplace_back("Can't interpret type \"" + type + "\" as bool.", loc);
}

inline void ExpectedIntError(const std::string& type, yy::location loc) {
    all_errors.emplace_back("Can't interpret type \"" + type + "\" as integer.", loc);
}


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

