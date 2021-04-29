#include "StClass.h"

StClass::StClass(Class *that_class)
{
    class_name_ = that_class->GetName();
    parent_class_ = that_class->GetParent();
    for (const auto &method : that_class->GetMethods())
    {
        methods_.emplace_back(method);
    }
    for (const auto &field : that_class->GetVariable())
    {
        fields_.emplace_back(*field->GetType());
    }
}

std::string StClass::GetName() const
{
    return class_name_;
}

std::string StClass::GetParent() const
{
    return parent_class_;
}

std::vector<StFunction> StClass::GetMethods() const
{
    return methods_;
}

std::vector<StVariable> StClass::GetFields() const
{
    return fields_;
}
