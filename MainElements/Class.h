#pragma once

#include "Visitors/Visitor.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "ExecBlocks/MethodDeclaration.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "SubsidiaryClasses/DeclarationList.h"
#include "BaseElements/BaseDeclaration.h"

class Class : public BaseDeclaration
{
public:
  void Accept(Visitor &visitor) override;
  ~Class() override = default;
  Class(std::string name, std::string parent_class);

  void initialize(DeclarationList *decl_list);
  void addMethod(MethodDeclaration *declaration);
  void addVariable(VariableDeclaration *declaration);

  std::string GetName() const;
  std::string GetParent() const;
  std::vector<VariableDeclaration *> GetVariable() const;
  std::vector<MethodDeclaration *> GetMethods() const;

private:
  std::string name_;
  std::string parent_class_;
  std::vector<VariableDeclaration *> variables_;
  std::vector<MethodDeclaration *> methods_;
};
