#include "ExprList.h"

ExprList::ExprList(BaseExpr *expression, yy::location loc)
{
    expressions.emplace_back(expression);
    location_ = loc;
}

void ExprList::addExpr(BaseExpr *expression)
{
    expressions.emplace_back(expression);
}

ExprList::~ExprList()
{
    for (auto expr : expressions)
    {
        delete expr;
    }
}

std::vector<BaseExpr *> ExprList::GetExpr() const
{
    return expressions;
}
