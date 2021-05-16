#include "MethodInvocation.h"

void MethodInvocation::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

MethodInvocation::MethodInvocation(BaseExpr *callable_expr, std::string name, ExprList *arguments, yy::location loc) :  BaseExpr(loc), BaseExecBlock(loc)
{
    callable_expr_ = callable_expr;
    name_ = std::move(name);
    arguments_ = arguments;
}

MethodInvocation::MethodInvocation(FieldExpr *callable_expr, ExprList *expr_list, yy::location loc) : BaseExpr(loc), BaseExecBlock(loc) 
{
    callable_expr_ = nullptr;
    expr_list = nullptr;
    name_ = callable_expr->GetName(); 
    arguments_ = expr_list;
    delete callable_expr_;
}
