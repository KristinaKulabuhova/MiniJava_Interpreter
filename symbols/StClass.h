#pragma once

#include "BaseSymbol.h"
#include "StFunction.h"

#include <vector>

class StClass: public BaseSymbol {
    std::vector<StFunction> methods_;
}