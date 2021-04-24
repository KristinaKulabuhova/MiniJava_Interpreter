#include "StClass.h"

StClass::StClass(Class *that_class) {
    class_name = that_class->name_;
    parent_class = that_class->parent_class_;
    for (const auto& method : that_class->methods_) {
        methods_.emplace_back(method);
    }
    for (const auto& field : that_class->variables_) {
        fields.emplace_back(*field->type_);
    }
}
