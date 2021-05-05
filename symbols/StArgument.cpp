#include "StArgument.h"

StArgument::StArgument(const VarTypeStr &type) : type_(type) {}

VarTypeStr StArgument::GetType() const
{
    return type_;
}
