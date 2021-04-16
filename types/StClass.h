#pragma once 

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include <types/Symbol.h>
#include "MainElements/Class.h"

class StClass : public Symbol {
public:
    explicit StClass(std::shared_ptr<Class> declaration);
    std::string getName() const;

//    int GetIntValue();
//
//    std::string GetTypeName();

private:
    std::string name_;
    std::shared_ptr<Class> declaration_;
};
