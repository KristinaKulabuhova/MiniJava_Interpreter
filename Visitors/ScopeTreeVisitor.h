#include "Visitor.h"
#include "AllIncludes.h"
#include "Scopes/BaseScope.h"

class ScopeTreeVisitor : public Visitor
{
  public:
    ScopeTreeVisitor() = default;

    void Visit(Program *program) override;

    void Visit(AtExpr *expression) override;
    void Visit(FieldExpr *expression) override;
    void Visit(NewArrExpr *expression) override;
    void Visit(NewCustomVarExpr *expression) override;

    void Visit(AndExpr *expression) override;
    void Visit(NotExpr *expression) override;
    void Visit(OrExpr *expression) override;

    void Visit(AddExpr *expression) override;
    void Visit(ModExpr *expression) override;
    void Visit(MulExpr *expression) override;
    void Visit(DivExpr *expression) override;
    void Visit(SubtractExpr *expression) override;

    void Visit(EqExpr *expression) override;
    void Visit(GEqExpr *expression) override;
    void Visit(GreaterExpr *expression) override;
    void Visit(NEqExpr *expression) override;
    void Visit(LEqExpr *expression) override;
    void Visit(LessExpr *expression) override;

    void Visit(IdentExpr *expression) override;
    void Visit(LengthExpr *expression) override;
    void Visit(NumExpr *expression) override;

    void Visit(FalseExpr *expression) override;
    void Visit(TrueExpr *expression) override;

    void Visit(Class *expression) override;
    void Visit(MainClass *expression) override;
    void Visit(MethodInvocation *expression) override;

    void Visit(If *branching) override;
    void Visit(While *expression) override;

    void Visit(MethodDeclaration *expression) override;
    void Visit(Println *expression) override;
    void Visit(Return *expression) override;
    void Visit(VariableDeclaration *expression) override;
    void Visit(AssertExpr *expression) override;
    void Visit(Assignment *assignment) override;
    void Visit(Block *expression) override;
    void Visit(ExecCode *expression) override;

    void Visit(Formals *formals) override;

  public:
    BaseScope *cur_scope = nullptr;
    BaseScope* global_scope_ = nullptr;
};