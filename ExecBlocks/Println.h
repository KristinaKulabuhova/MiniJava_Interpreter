#ifndef PASCAL_PRINTLN_H
#define PASCAL_PRINTLN_H

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Println : public BaseExecBlock {
  public:
    BaseExpr* expression;

    explicit Println(BaseExpr* expression);
    int Accept(Visitor& visitor) override;
    ~Println() override;
};


#endif //PASCAL_PRINTLN_H
