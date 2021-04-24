#include "ScopeTreeVisitor.h"

#include <memory>

void ScopeTreeVisitor::Visit(Program *program) {
    cur_scope = new BaseScope();
    global_scope_ = cur_scope;
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->classes) {
        class_decl->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(AtExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(FieldExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(NewArrExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(NewCustomVarExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(AndExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(NotExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(OrExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(AddExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(ModExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(MulExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(DivExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(SubtractExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(EqExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(GEqExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(GreaterExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(NEqExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(LEqExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(LessExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(IdentExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(LengthExpr */*expression*/) {
    
}


void ScopeTreeVisitor::Visit(NumExpr */*expression*/) {
    
}


void ScopeTreeVisitor::Visit(FalseExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(TrueExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Class *expression) {

    cur_scope->elements[expression->name_] = new StClass(expression);
    for (auto& field : expression->variables_) {
        field->Accept(*this);
    }
    for (auto& method : expression->methods_) {
        method->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
    
}

void ScopeTreeVisitor::Visit(MethodInvocation */*expression*/) {
    
}


void ScopeTreeVisitor::Visit(If* branching) {
    if (dynamic_cast<Block*>(branching->true_branch)) {
        auto old_scope = cur_scope;
        cur_scope->children_.emplace_back(new BaseScope);
        cur_scope = cur_scope->children_.back();

        branching->true_branch->Accept(*this);

        cur_scope = old_scope;
    }
    if (dynamic_cast<Block*>(branching->false_branch)) {
        auto old_scope = cur_scope;
        cur_scope->children_.emplace_back(new BaseScope);
        cur_scope = cur_scope->children_.back();

        branching->false_branch->Accept(*this);

        cur_scope = old_scope;
    }
}

void ScopeTreeVisitor::Visit(While* expression) {
    if (dynamic_cast<Block*>(expression->cycle_body)) {
        auto old_scope = cur_scope;
        cur_scope->children_.emplace_back(new BaseScope);
        cur_scope = cur_scope->children_.back();

        expression->cycle_body->Accept(*this);

        cur_scope = old_scope;
    }
}


void ScopeTreeVisitor::Visit(MethodDeclaration *expression) {
    cur_scope->elements[expression->name_] = new StFunction(expression);
    auto old_scope = cur_scope;
    cur_scope->children_.emplace_back(new BaseScope);
    cur_scope = cur_scope->children_.back();

    if (expression->arguments_) {
        for (const auto &argument : expression->arguments_->variables) {
            cur_scope->elements[argument->name_] = new StVariable(*argument);
        }
    }
    expression->exec_code_->Accept(*this);

    cur_scope = old_scope;
    
}

void ScopeTreeVisitor::Visit(Println */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Return */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(VariableDeclaration *expression) {
    cur_scope->elements[expression->name_] = new StVariable(*expression->type_);
}

void ScopeTreeVisitor::Visit(AssertExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Assignment */*assignment*/) {
    
}

void ScopeTreeVisitor::Visit(Block *expression) {
    auto old_scope = cur_scope;
    cur_scope->children_.emplace_back(new BaseScope);
    cur_scope = cur_scope->children_.back();

    expression->exec_code->Accept(*this);

    cur_scope = old_scope;
}

void ScopeTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->program_lines_) {
        program_block->Accept(*this);
    }
    
}

void ScopeTreeVisitor::Visit(Formals */*formals*/) {

}
