#ifndef MINI_JAVA_STVARIABLE_H
#define MINI_JAVA_STVARIABLE_H

#include <string>
#include <memory>

#include "Symbol.h"
#include "ExecBlocks/VariableDeclaration.h"

class StVariable : public Symbol {
  public:
    explicit StVariable(std::shared_ptr<VariableDeclaration>  declaration);
    std::string getName() const;
  private:
    std::string name_;
    std::shared_ptr<VariableDeclaration> declaration_;
};


#endif //MINI_JAVA_STVARIABLE_H
