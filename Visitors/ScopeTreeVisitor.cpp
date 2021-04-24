#include "ScopeTreeVisitor.h"

#include <memory>

ScopeTreeVisitor::ScopeTreeVisitor() : tree_(std::make_shared<ScopeLayer>()), current_layer_(tree_.getRoot()), blocks_counter_(0) {}

void ScopeTreeVisitor::Visit(Program *program) {
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

    auto prev_layer = current_layer_;
    current_layer_ = std::make_shared<ScopeLayer>(current_layer_->weak_from_this(), expression->name_);
    prev_layer->AddChild(current_layer_);
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


void ScopeTreeVisitor::Visit(If */*branching*/) {
    
}

void ScopeTreeVisitor::Visit(While */*expression*/) {
    
}


void ScopeTreeVisitor::Visit(MethodDeclaration *expression) {
    blocks_counter_ = 0;
    current_layer_->Put(expression->getName(),
                        std::make_shared<StFunction>(std::shared_ptr<MethodDeclaration>(expression)));
    auto prev_layer = current_layer_;
    current_layer_ = std::make_shared<ScopeLayer>(current_layer_->weak_from_this(), expression->getName());
    prev_layer->AddChild(current_layer_);
    for (auto& argument : expression->getFormals()->variables) {
        VariableDeclaration(argument.first, argument.second).Accept(*this);
    }
    expression->getCode()->Accept(*this);
    
}

void ScopeTreeVisitor::Visit(Println */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Return */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(VariableDeclaration *expression) {
    current_layer_->Put(expression->getName(),
                        std::make_shared<StVariable>(std::shared_ptr<VariableDeclaration>(expression)));
    
}

void ScopeTreeVisitor::Visit(AssertExpr */*expression*/) {
    
}

void ScopeTreeVisitor::Visit(Assignment */*assignment*/) {
    
}

void ScopeTreeVisitor::Visit(Block *expression) {
    auto prev_layer = current_layer_;
    current_layer_ = std::make_shared<ScopeLayer>(current_layer_->weak_from_this(),
                                                  std::to_string(blocks_counter_++));
    prev_layer->AddChild(current_layer_);
    auto prev_blocks_counter = blocks_counter_;
    blocks_counter_ = 0;
    expression->exec_code->Accept(*this);
    blocks_counter_ = prev_blocks_counter;
    
}

void ScopeTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->program_lines_) {
        program_block->Accept(*this);
    }
    
}

std::shared_ptr<ScopeLayer> ScopeTreeVisitor::GetTree() {
    return tree_.getRoot();
}
