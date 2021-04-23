#include "StFunction.h"

StFunction::StFunction(MethodDeclaration *function) {
  name = function->name_;
  for (auto argument: function->arguments_->variables) {
    arguments.emplace_back(argument.second);
  }

}