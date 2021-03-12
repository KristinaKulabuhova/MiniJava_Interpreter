#include "ExprList.h"

ExprList::ExprList(BaseExpr *expression) {
    expressions.emplace_back(expression);
}

void ExprList::addExpr(BaseExpr *expression) {
    expressions.emplace_back(expression);
}
