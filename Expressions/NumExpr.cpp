#include "NumExpr.h"

NumExpr::NumExpr(const std::string &number)
{
    value = std::stoi(number);
    //    strtol(number.c_str(), &p_chr, 10);
    //    if (*p_chr) {
    //        value = std::string(number.cbegin() + 1, number.cend() - 1);
    //    } else {
    //        value = std::stoi(number);
    //    }
}

void NumExpr::Accept(Visitor &visitor)
{
    visitor.Visit(this);
}
