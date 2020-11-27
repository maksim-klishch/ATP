#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include <vector>

#include "operator.h"

class BinaryOperator : public Operator
{
protected:
    Term *left, *right;
public:
    BinaryOperator();
    BinaryOperator(Term* left, Term* right);

    virtual ~BinaryOperator();

    virtual void setLeftOperand(Term* term);
    virtual void setRightOperand(Term* term);
    virtual void setOperands(Term* left, Term* right);

    virtual Term* getLeftOperand() const;
    virtual Term* getRightOperand() const;

    virtual std::string toString() const;
};

#endif //BINARYOPERATOR_H
