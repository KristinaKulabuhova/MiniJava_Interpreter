#pragma once

#include "BaseSymbol.h"
#include "StFunction.h"
#include "MainElements/Class.h"

#include <vector>

class StClass: public BaseSymbol {
  public:
    explicit StClass(Class* that_class);

  public:
    std::string class_name;
    std::string parent_class;
    std::vector<StFunction> methods_;
    std::vector<StVariable> fields;
};
