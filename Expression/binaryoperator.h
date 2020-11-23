#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include <vector>

#include "term.h"

class BinaryOperator : public Term
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

    virtual Term* getLeftOperand();
    virtual Term* getRightOperand();

    virtual std::string toString() const;
};

#endif //BINARYOPERATOR_H
