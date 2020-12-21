#ifndef PARSEREXAMPLE_INTERPRETER_H
#define PARSEREXAMPLE_INTERPRETER_H

#include "VarDeclList/VarDeclList.h"
#include "Visitor.h"
#include "Elements.h"

#include <map>
#include <stdexcept>
#include <iostream>

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

class Interpreter : public Visitor {
  public:
    std::map<std::string, var_t> var_value;
    explicit Interpreter(const std::vector<VarDeclList*>& var_decl_list);
    var_t Visit(AddExpr* expression) override;
    var_t Visit(DivExpr* expression) override;
    var_t Visit(ModExpr* expression) override;
    var_t Visit(MulExpr* expression) override;
    var_t Visit(SubtractExpr* expression) override;
    var_t Visit(IdentExpr* expression) override;
    var_t Visit(ConstExpr* expression) override;

    var_t Visit(LessExpr* expression) override;
    var_t Visit(GreaterExpr* expression) override;
    var_t Visit(LeqExpr* expression) override;
    var_t Visit(GeqExpr* expression) override;
    var_t Visit(EqExpr* expression) override;
    var_t Visit(NEqExpr* expression) override;
    var_t Visit(AndExpr* expression) override;
    var_t Visit(OrExpr* expression) override;
    var_t Visit(NotExpr* expression) override;

    void Visit(Assignment* assignment) override;
    void Visit(ExecCode* code) override;
    void Visit(If* branching) override;
    void Visit(While* while_cycle) override;
    void Visit(For* for_cycle) override;
    void Visit(Read* read_module) override;
    void Visit(Write* write_module) override;
    void CheckOperationCorrectness(const std::string& operation, bool only_for_numbers, const var_t& first_val, const var_t& second_val);
    void CheckBoolCorrectness(const var_t& val);
    void CheckIntCorrectness(const var_t& val);
    void GetType(std::pair<int, std::string>& type, const var_t& val);
};


#endif //PARSEREXAMPLE_INTERPRETER_H
