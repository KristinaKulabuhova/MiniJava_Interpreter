
#include "Interpreter.h"

//void Interpreter::Visit(AtExpr* /*expression*/) {}
void Interpreter::Visit(FieldExpr* /*expression*/) {}
void Interpreter::Visit(NewArrExpr* /*expression*/) {}
void Interpreter::Visit(NewCustomVarExpr* /*expression*/) {}

void Interpreter::Visit(AndExpr* /*expression*/) {}
void Interpreter::Visit(NotExpr* /*expression*/) {}
void Interpreter::Visit(OrExpr* /*expression*/) {}

void Interpreter::Visit(AddExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;

    expression->p_rhs->Accept(*this);
    value += tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(ModExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;

    expression->p_rhs->Accept(*this);
    value %= tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(MulExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;

    expression->p_rhs->Accept(*this);
    value *= tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(DivExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;

    expression->p_rhs->Accept(*this);
    value /= tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(SubtractExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;

    expression->p_rhs->Accept(*this);
    value -= tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(EqExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value == tos_value_);
}

void Interpreter::Visit(GEqExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value >= tos_value_);
}

void Interpreter::Visit(GreaterExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value > tos_value_);
}

void Interpreter::Visit(NEqExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value != tos_value_);
}

void Interpreter::Visit(LEqExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value <= tos_value_);
}

void Interpreter::Visit(LessExpr* expression) {
    int value = 0;
    expression->p_lhs->Accept(*this);
    value += tos_value_;
    expression->p_rhs->Accept(*this);

    SetTosValue(value < tos_value_);
}  

void Interpreter::Visit(IdentExpr* expression) {
    SetTosValue(variables_[expression->var_name_]);
    curr_name_ = expression->var_name_;
}

void Interpreter::Visit(LengthExpr* /*expression*/) {}

void Interpreter::Visit(NumExpr* expression) {
    SetTosValue(expression->value);
}

void Interpreter::Visit(FalseExpr* /*expression*/) {
    SetTosValue(false);
}
void Interpreter::Visit(TrueExpr* /*expression*/) {
    SetTosValue(true);
}

void Interpreter::Visit(Class* /*expression*/) {}

void Interpreter::Visit(MainClass* expression) {
    expression->methods_[0]->Accept(*this);
}
void Interpreter::Visit(MethodInvocation* /*expression*/) {}

void Interpreter::Visit(If* branching) {
    branching->statement->Accept(*this);

	if (tos_value_) {
        branching->true_branch->Accept(*this);
	} else if (branching->false_branch != nullptr) {
		branching->false_branch->Accept(*this);
	}

	UnsetTosValue();
}

void Interpreter::Visit(While* expression) {
    expression->statement->Accept(*this);
	while(tos_value_) {
	    expression->cycle_body->Accept(*this);
	}
	UnsetTosValue();
}

void Interpreter::Visit(MethodDeclaration* expression) {
    for (auto& line : expression->exec_code_->program_lines_) {
        line->Accept(*this);
    }
}

void Interpreter::Visit(Println* expression) {
    expression->expression->Accept(*this);
	std::cout << tos_value_ << '\n';
	UnsetTosValue();
}

void Interpreter::Visit(Return* /*expression*/) {}

void Interpreter::Visit(VariableDeclaration* expression) {
    variables_[expression->name_] = 0;
}
void Interpreter::Visit(AssertExpr* expression) {
    expression->expression->Accept(*this);
	assert(tos_value_);
	UnsetTosValue();
}

void Interpreter::Visit(Assignment* assignment) {
//    assignment->to->Accept(*this);
	assignment->from->Accept(*this);
	variables_[assignment->to->var_name_] = tos_value_;
	UnsetTosValue();
}

void Interpreter::Visit(Block* expression) {
    expression->exec_code->Accept(*this);
}

void Interpreter::Visit(ExecCode* /*expression*/) {}

void Interpreter::Visit(Program* program) {
    program->main_class->Accept(*this);
}

void Interpreter::Visit(Formals* /*formals*/) {}

void Interpreter::SetTosValue(int value) {
	is_tos_expr_ = true;
	tos_value_ = value;
}

void Interpreter::UnsetTosValue() {
	is_tos_expr_ = false;
	tos_value_ = 0;
}

void Interpreter::Visit(AtExpr */*expression*/) {}
