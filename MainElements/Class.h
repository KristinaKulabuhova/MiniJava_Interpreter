#ifndef PARSEREXAMPLE_BASECLASS_H
#define PARSEREXAMPLE_BASECLASS_H

#include "Visitors/Visitor.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "ExecBlocks/MethodDeclaration.h"
#include "ExecBlocks/VariableDeclaration.h"
#include "SubsidiaryClasses/DeclarationList.h"
#include "BaseElements/BaseDeclaration.h"

class Class : public BaseDeclaration{
  public:
    int Accept(Visitor& visitor) override;
    ~Class() override;
    Class(std::string name, std::string parent_class);
    void initialize(DeclarationList* decl_list);
    void addMethod(MethodDeclaration* declaration);
    void addVariable(VariableDeclaration* declaration);

  public:
    std::string name_;
    std::string parent_class_;
    std::vector<VariableDeclaration*> variables_;
    std::vector<MethodDeclaration*> methods_;
};

#endif //PARSEREXAMPLE_BASECLASS_H