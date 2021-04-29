#include "NotExpr.h"

NotExpr::NotExpr(BaseExpr *p_expr) : p_expr(p_expr) {}

NotExpr::~NotExpr()
{
    delete p_expr;
}

void NotExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}

BaseExpr* NotExpr::GetExpression() const {
    return p_expr;
}

