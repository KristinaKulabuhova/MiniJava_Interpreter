#include "ScopeTreeVisitor.h"

#include <memory>

ScopeTreeVisitor::SymbolTreeVisitor() :
tree_(std::make_shared<ScopeLayer>()), current_layer_(tree_.getRoot()), blocks_counter_(0) {}

int SymbolTreeVisitor::Visit(AtExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(FieldExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(NewArrExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(NewCustomVarExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(AndExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(NotExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(OrExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(AddExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(ModExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(MulExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(DivExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(SubtractExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(EqExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(GEqExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(GreaterExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(NEqExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(LEqExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(LessExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(IdentExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(LengthExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(VarExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(NumExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(ThisExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(FalseExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(TrueExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(Class *expression) {

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

int SymbolTreeVisitor::Visit(MainClass *expression) {
    expression->Class::Accept(*this);
    return 0;
}

int SymbolTreeVisitor::Visit(MethodInvocation */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(For */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(If */*branching*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(While */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(Lvalue */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(MethodDeclaration *expression) {
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

int SymbolTreeVisitor::Visit(Println */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(Return */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(VariableDeclaration *expression) {
    current_layer_->Put(expression->getName(),
                        std::make_shared<StVariable>(std::shared_ptr<VariableDeclaration>(expression)));
    return 0;
}

int SymbolTreeVisitor::Visit(AssertExpr */*expression*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(Assignment */*assignment*/) {
    return 0;
}

int SymbolTreeVisitor::Visit(Block *expression) {
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

int SymbolTreeVisitor::Visit(ExecCode *expression) {
    for (auto& program_block : expression->program_lines_) {
        program_block->Accept(*this);
    }
    return 0;
}

int SymbolTreeVisitor::Visit(Program *program) {
    program->main_class->Accept(*this);
    for (auto& class_decl : program->class_decl_list->classes) {
        class_decl->Accept(*this);
    }
    return 0;
}

std::shared_ptr<ScopeLayer> SymbolTreeVisitor::GetTree() {
    return tree_.getRoot();
}
