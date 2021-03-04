#ifndef RETURN_H
#define RETURN_H

#include "BaseElements/BaseExecBlock.h"

class Return : public Statement {
public:
    Return(Expression value);

    void Accept(Visitor&  visitor) override;

    std::shared_ptr<Expression> value;
};

#endif