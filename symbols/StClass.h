#pragma once

#include "BaseSymbol.h"
#include "StFunction.h"
#include "MainElements/Class.h"

#include <vector>

class StClass: public BaseSymbol {
  public:
    explicit StClass(Class* that_class);

    std::string GetName() const;
    std::string GetParent() const;
    std::vector<StFunction> GetMethods() const;
    std::vector<StVariable> GetFields() const;

  private:
    std::string class_name_;
    std::string parent_class_;
    std::vector<StFunction> methods_;
    std::vector<StVariable> fields_;
};
