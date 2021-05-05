#pragma once


class BaseDeclaration {
  public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~BaseDeclaration() = default;
};

