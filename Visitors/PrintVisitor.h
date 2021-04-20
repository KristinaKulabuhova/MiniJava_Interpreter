#ifndef MINI_JAVA_PRINTVISITOR_H
#define MINI_JAVA_PRINTVISITOR_H

#include "Visitor.h"
#include "Elements.h"
#include <iostream>
#include <string>


class PrintVisitor : public Visitor {
  public:
    int Visit(AtExpr* expression) override;
    int Visit(FieldExpr* expression) override;
    int Visit(NewArrExpr* expression) override;
    int Visit(NewCustomVarExpr* expression) override;

    int Visit(AndExpr* expression) override;
    int Visit(NotExpr* expression) override;
    int Visit(OrExpr* expression) override;

    int Visit(AddExpr* expression) override;
    int Visit(ModExpr* expression) override;
    int Visit(MulExpr* expression) override;
    int Visit(DivExpr* expression) override;
    int Visit(SubtractExpr* expression) override;

    int Visit(EqExpr* expression) override;
    int Visit(GEqExpr* expression) override;
    int Visit(GreaterExpr* expression) override;
    int Visit(NEqExpr* expression) override;
    int Visit(LEqExpr* expression) override;
    int Visit(LessExpr* expression) override;

    int Visit(IdentExpr* expression) override;
    int Visit(LengthExpr* expression) override;
    int Visit(VarExpr* expression) override;
    int Visit(NumExpr* expression) override;
    int Visit(ThisExpr* expression) override;

    int Visit(FalseExpr* expression) override;
    int Visit(TrueExpr* expression) override;

    int Visit(Class* expression) override;
    int Visit(MainClass* expression) override;
    int Visit(MethodInvocation* expression) override;

    int Visit(For* expression) override;
    int Visit(If* branching) override;
    int Visit(While* expression) override;

    int Visit(Lvalue* expression) override;
    int Visit(MethodDeclaration* expression) override;
    int Visit(Println* expression) override;
    int Visit(Return* expression) override;
    int Visit(VariableDeclaration* expression) override;
    int Visit(AssertExpr* expression) override;
    int Visit(Assignment* assignment) override;
    int Visit(Block* expression) override;
    int Visit(ExecCode* expression) override;

    int Visit(Program* program) override;

    int Visit(Formals* formals) override;

  private:
    size_t tabs_counter_ = 0;
    void printTabs() const;

    void printVarTypeStr(const VarTypeStr& var_type_str);
};


#endif //MINI_JAVA_PRINTVISITOR_H