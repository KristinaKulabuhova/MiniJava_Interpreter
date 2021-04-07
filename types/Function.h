#pragma once 

#include <program/declaration/method.h>
#include <types/Object.h>

#include <string>
#include <vector>

class FunctionObject : public Object {
public:
    FunctionObject(std::shared_ptr<MethodDecl> declaration);

    int GetIntValue() override;

    std::string GetTypeName() override;

private:
    std::string name_;
    std::vector<std::shared_ptr<Object>> arguments_;
    std::vector<std::string> argument_names_;
    std::shared_ptr<MethodDecl> body_;
};
