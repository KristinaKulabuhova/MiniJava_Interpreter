#include "StFunction.h"

StFunction::StFunction(MethodDeclaration *function) : return_type_(*function->GetType()) {
  //name_ = function->GetName();
  if (function->GetFormals()) {
      arguments_.reserve(function->GetFormals()->GetVariables().size());
      for (auto argument: function->GetFormals()->GetVariables()) {
          arguments_.emplace_back(*argument);
      }
  }
}