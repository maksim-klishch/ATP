#ifndef NOT_H
#define NOT_H

#include "Expression/unaryoperator.h"

class NOT : public UnaryOperator
{
public:
    NOT();
    NOT(Term* operand);

    Term* getCopy() const;
    std::string getType() const;

    Term* simplification() const;
};

#endif // NOT_H
