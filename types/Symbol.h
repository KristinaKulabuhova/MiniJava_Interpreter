#pragma once

class Symbol {
 public:
    virtual int ToInt();
    virtual ~Symbol() = default;
};