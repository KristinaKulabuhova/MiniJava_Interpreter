#include <Visitor.h>
#include <AllIncludes.h>

class SymbilTreeVisitor : public Visitor
{
    SymbilTreeVisitor();

    void Visit(Program *program);

    void Visit(AtExpr *expression);
    void Visit(FieldExpr *expression);
    void Visit(NewArrExpr *expression);
    void Visit(NewCustomVarExpr *expression);

    void Visit(AndExpr *expression);
    void Visit(NotExpr *expression);
    void Visit(OrExpr *expression);

    void Visit(AddExpr *expression);
    void Visit(ModExpr *expression);
    void Visit(MulExpr *expression);
    void Visit(DivExpr *expression);
    void Visit(SubtractExpr *expression);

    void Visit(EqExpr *expression);
    void Visit(GEqExpr *expression);
    void Visit(GreaterExpr *expression);
    void Visit(NEqExpr *expression);
    void Visit(LEqExpr *expression);
    void Visit(LessExpr *expression);

    void Visit(IdentExpr *expression);
    void Visit(LengthExpr *expression);
    void Visit(NumExpr *expression);

    void Visit(FalseExpr *expression);
    void Visit(TrueExpr *expression);

    void Visit(Class *expression);
    void Visit(MainClass *expression);
    void Visit(MethodInvocation *expression);

    void Visit(If *branching);
    void Visit(While *expression);

    void Visit(MethodDeclaration *expression);
    void Visit(Println *expression);
    void Visit(Return *expression);
    void Visit(VariableDeclaration *expression);
    void Visit(AssertExpr *expression);
    void Visit(Assignment *assignment);
    void Visit(Block *expression);
    void Visit(ExecCode *expression);

    void Visit(Formals *formals);
};