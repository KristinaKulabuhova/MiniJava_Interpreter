#pragma once 

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include <types/Object.h>

class ClassObject : public Object {
public:
    ClassObject(
            const std::vector<std::string>& field_names,
            const std::vector<std::shared_ptr<Object>>& values,
            const std::string& class_name
    );

    int GetIntValue() override;

    std::string GetTypeName() override;

    std::vector<std::shared_ptr<Object>> GetFieldValues();
    void SetFieldValues(std::vector<std::shared_ptr<Object>>& values);

private:
    std::string name_;
    std::vector<std::shared_ptr<Object>> fields_;
    std::vector<std::string> field_names_;
    std::unordered_map<std::string, size_t> fields_offsets_;
};
