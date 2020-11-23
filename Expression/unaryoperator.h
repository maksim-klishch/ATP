#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "term.h"

class UnaryOperator : public Term
{
protected:
    Term* operand;
public:
    UnaryOperator();
    UnaryOperator(Term* operand);
    virtual ~UnaryOperator();

    void setOperand(Term* operand);
    Term* getOperand();

    virtual std::string toString() const;
};

#endif // UNARYOPERATOR_H
