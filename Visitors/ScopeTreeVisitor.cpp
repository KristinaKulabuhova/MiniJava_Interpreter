#include "ScopeTreeVisitor.h"

#include <memory>

ScopeTreeVisitor::SymbolTreeVisitor() : tree_(std::make_shared<ScopeLayer>()), current_layer_(tree_.getRoot()), blocks_counter_(0) {}

void SymbolTreeVisitor::Visit(AtExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(FieldExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(NewArrExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(NewCustomVarExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(AndExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(NotExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(OrExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(AddExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(ModExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(MulExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(DivExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(SubtractExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(EqExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(GEqExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(GreaterExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(NEqExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(LEqExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(LessExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(IdentExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(LengthExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(VarExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(NumExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(ThisExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(FalseExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(TrueExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(Class *expression) {

    auto prev_layer = current_layer_;
    current_layer_ = std::make_shared<ScopeLayer>(current_layer_->weak_from_this(), expression->name_);
    prev_layer->AddChild(current_layer_);
    for (auto& field : expression->variables_) {
        field->Accept(*this);
    }
    for (auto& method : expression->methods_) {
        method->Accept(*this);
    }
    return 0;
}

void SymbolTreeVisitor::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
    return 0;
}

void SymbolTreeVisitor::Visit(MethodInvocation */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(For */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(If */*branching*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(While */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(Lvalue */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(MethodDeclaration *expression) {
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
    return 0;
}

void SymbolTreeVisitor::Visit(Println */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(Return */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(VariableDeclaration *expression) {
    current_layer_->Put(expression->getName(),
                        std::make_shared<StVariable>(std::shared_ptr<VariableDeclaration>(expression)));
    return 0;
}

void SymbolTreeVisitor::Visit(AssertExpr */*expression*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(Assignment */*assignment*/) {
    return 0;
}

void SymbolTreeVisitor::Visit(Block *expression) {
    auto prev_layer = current_layer_;
    current_layer_ = std::make_shared<ScopeLayer>(current_layer_->weak_from_this(),
                                                  std::to_string(blocks_counter_++));
    prev_layer->AddChild(current_layer_);
    auto prev_blocks_counter = blocks_counter_;
    blocks_counter_ = 0;
    expression->exec_code->Accept(*this);
    blocks_counter_ = prev_blocks_counter;
    return 0;
}

void SymbolTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->program_lines_) {
        program_block->Accept(*this);
    }
    return 0;
}

void SymbolTreeVisitor::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->classes) {
        class_decl->Accept(*this);
    }
    return 0;
}

std::shared_ptr<ScopeLayer> SymbolTreeVisitor::GetTree() {
    return tree_.getRoot();
}
