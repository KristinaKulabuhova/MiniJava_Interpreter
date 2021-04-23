#include<Visitor.h>

int Visit(AtExpr* expression) {
    return 0;
}

int Visit(FieldExpr* expression)
int Visit(NewArrExpr* expression)
int Visit(NewCustomVarExpr* expression)

int Visit(AndExpr* expression)
int Visit(NotExpr* expression)
int Visit(OrExpr* expression)

int Visit(AddExpr* expression) {

}
int Visit(ModExpr* expression)
int Visit(MulExpr* expression)
int Visit(DivExpr* expression)
int Visit(SubtractExpr* expression)

int Visit(EqExpr* expression)
int Visit(GEqExpr* expression)
int Visit(GreaterExpr* expression)
int Visit(NEqExpr* expression)
int Visit(LEqExpr* expression)
int Visit(LessExpr* expression)  

int Visit(IdentExpr* expression)
int Visit(LengthExpr* expression)
int Visit(VarExpr* expression)
int Visit(NumExpr* expression)
int Visit(ThisExpr* expression)

int Visit(FalseExpr* expression)
int Visit(TrueExpr* expression)

int Visit(Class* expression)
int Visit(MainClass* expression)
int Visit(MethodInvocation* expression)

int Visit(For* expression)
int Visit(If* branching)
int Visit(While* expression)

int Visit(Lvalue* expression)
int Visit(MethodDeclaration* expression)
int Visit(Println* expression)
int Visit(Return* expression)
int Visit(VariableDeclaration* expression)
int Visit(AssertExpr* expression)
int Visit(Assignment* assignment)
int Visit(Block* expression)
int Visit(ExecCode* expression)  

int Visit(Program* program) {
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->classes) {
        class_decl->Accept(*this);
    }
    return 0;
}

int Visit(Formals* formals)