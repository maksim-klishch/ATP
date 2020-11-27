#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "operator.h"

class UnaryOperator : public Operator
{
protected:
    Term* operand;
public:
    UnaryOperator();
    UnaryOperator(Term* operand);
    virtual ~UnaryOperator();

    void setOperand(Term* operand);
    Term* getOperand() const;

    virtual std::string toString() const;
};

#endif // UNARYOPERATOR_H
