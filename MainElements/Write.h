#ifndef PARSEREXAMPLE_WRITE_H
#define PARSEREXAMPLE_WRITE_H

#include "BaseElements/BaseExecBlock.h"
#include "BaseElements/BaseExpr.h"

class Write : public BaseExecBlock {
  public:
    BaseExpr* expression;
    explicit Write(BaseExpr* expression);
    ~Write() override;
    void Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_WRITE_H
