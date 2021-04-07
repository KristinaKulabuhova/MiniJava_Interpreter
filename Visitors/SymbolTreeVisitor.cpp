#include "SymbolTreeVisitor.h"

#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(NumExpr* expression) {
}

void SymbolTreeVisitor::Visit(AddExpr** expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(SubtractExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(MulExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(DivExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(ModExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(IdentExpr* expression) { //?
    expression->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(StatementList* assignment_list) {
    for (Statement* assignment: assignment_list->statements_) {
        assignment->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(VarDecl* var_decl) {
    std::cout << "Declaring var " << var_decl->variable_ << std::endl;
    current_layer_->DeclareVariable(Symbol(var_decl->variable_));
}

void SymbolTreeVisitor::Visit(ScopeAssignmentList* list) {
    auto new_layer = new ScopeLayer(current_layer_);

    current_layer_ = new_layer;
    list->statement_list->Accept(this);
    current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(Program* program) {
    program->assignments_->Accept(this);
    program->expression_->Accept(this); // tos value is called
}

void SymbolTreeVisitor::Visit(AssertExpr* expression) {
    expression->expression->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(Return* expression) {
    expression->expression->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(Println* expression) {
    expression->expression->Accept(shared_from_this());
}

std::shared_ptr<ScopeLayerTree> SymbolTreeVisitor::GetTree() {
    return std::shared_ptr<ScopeLayerTree>(&tree_);
}

void SymbolTreeVisitor::Visit(AtExpr* expression) {} //
void SymbolTreeVisitor::Visit(FieldExpr* expression) {} //

void SymbolTreeVisitor::Visit(NewArrExpr* expression) {
    // Not supported
}

void SymbolTreeVisitor::Visit(NewCustomVarExpr* expression) {} //

void SymbolTreeVisitor::Visit(AndExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(NotExpr* expression) {
    expression->p_expr->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(OrExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(EqExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(GEqExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(GreaterExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(NEqExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(LEqExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(LessExpr* expression) {
    expression->p_lhs->Accept(shared_from_this());
    expression->l_lhs->Accept(shared_from_this());
}  
    
void SymbolTreeVisitor::Visit(IdentExpr* expression) {} //

void SymbolTreeVisitor::Visit(LengthExpr* expression) {
    // Not supported
}

void SymbolTreeVisitor::Visit(VarExpr* expression) {} //

void SymbolTreeVisitor::Visit(ThisExpr* expression) {

}
    
void SymbolTreeVisitor::Visit(FalseExpr* expression) {
}

void SymbolTreeVisitor::Visit(TrueExpr* expression) {
}

void SymbolTreeVisitor::Visit(Class* expression) {} // про обходы подумать
void SymbolTreeVisitor::Visit(MainClass* expression) {} // про обходы подумать
void SymbolTreeVisitor::Visit(MethodInvocation* expression) {} // про обходы подумать

void SymbolTreeVisitor::Visit(For* expression) {} //

void SymbolTreeVisitor::Visit(If* branching) {
    expression->statement->Accept(shared_from_this());
    expression->true_branch->Accept(shared_from_this());
    if (expression->false_branch) {
        expression->false_branch->Accept(shared_from_this());
    }
}

void SymbolTreeVisitor::Visit(While* expression) {
    expression->statement->Accept(shared_from_this());
    expression->cycle_body->Accept(shared_from_this());
}

void SymbolTreeVisitor::Visit(Lvalue* expression) {} //
void SymbolTreeVisitor::Visit(MethodDeclaration* expression) {} //
    
    
void SymbolTreeVisitor::Visit(VariableDeclaration* expression) {} // про обходы подумать
void SymbolTreeVisitor::Visit(Assignment* assignment) {} //
void SymbolTreeVisitor::Visit(Block* expression) {} //
void SymbolTreeVisitor::Visit(ExecCode* expression) {}  //