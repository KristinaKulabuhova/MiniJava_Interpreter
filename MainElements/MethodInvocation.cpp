#include "MethodInvocation.h"

void MethodInvocation::Accept(Visitor &visitor) {
    visitor.Visit(this);
}

MethodInvocation::MethodInvocation(BaseExpr *callable_expr, std::string name, ExprList *arguments) :
callable_expr(callable_expr), name(std::move(name)), arguments(arguments) {}

MethodInvocation::MethodInvocation(FieldExpr *callable_expr, ExprList *expr_list) :
callable_expr(nullptr),  name(callable_expr->name), arguments(expr_list) {
    delete callable_expr;
}
