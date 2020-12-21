#ifndef PARSEREXAMPLE_READ_H
#define PARSEREXAMPLE_READ_H


#include "BaseElements/BaseExecBlock.h"

#include <string>

class Read : BaseExecBlock {
  public:
    std::string var_name;
    explicit Read(std::string var_name);
    ~Read() override = default;
    void Accept(Visitor& visitor) override;
};


#endif //PARSEREXAMPLE_READ_H
