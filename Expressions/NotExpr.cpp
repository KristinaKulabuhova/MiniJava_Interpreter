#include "NotExpr.h"

NotExpr::NotExpr(BaseExpr *p_expr, yy::location loc) : BaseExpr(loc) 
{
    p_expr_ = p_expr;
}

void NotExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr* NotExpr::GetExpression() const {
    return p_expr_;
}

