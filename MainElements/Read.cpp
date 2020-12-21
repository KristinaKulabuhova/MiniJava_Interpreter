#include "Read.h"

Read::Read(std::string var_name) : var_name(std::move(var_name)) {}

void Read::Accept(Visitor &visitor) {
    visitor.Visit(this);
}
