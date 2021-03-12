#ifndef MINI_JAVA_BASEDECLARATION_H
#define MINI_JAVA_BASEDECLARATION_H


class BaseDeclaration {
  public:
    virtual int Accept(Visitor& visitor) = 0;
    virtual ~BaseExpr() = default;
};

#endif //MINI_JAVA_BASEDECLARATION_H
