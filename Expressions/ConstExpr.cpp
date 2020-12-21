#include "ConstExpr.h"

ConstExpr::ConstExpr(const std::string &tmp_val) {
    char* p_chr;
    strtol(tmp_val.c_str(), &p_chr, 10);
    if (*p_chr) {
        value = std::string(tmp_val.cbegin() + 1, tmp_val.cend() - 1);
    } else {
        value = std::stoi(tmp_val);
    }
}

var_t ConstExpr::Accept(Visitor &visitor) {
    return visitor.Visit(this);
}
