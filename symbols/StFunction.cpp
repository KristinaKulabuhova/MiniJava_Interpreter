#include "StFunction.h"

StFunction::StFunction(MethodDeclaration *function) : return_type(*function->return_type_) {
  name = function->name_;
  arguments.reserve(function->arguments_->variables.size());
  for (auto argument: function->arguments_->variables) {
    arguments.emplace_back(*argument);
  }
}