#include <VarType.h>

VarTypeStr::VarTypeStr(SimpleType *simple_type, bool array = false) : type(simple_type->type_id), array(array), name_(simple_type->type_name_) {}