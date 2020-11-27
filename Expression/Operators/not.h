#ifndef NOT_H
#define NOT_H

#include "Expression/unaryoperator.h"

class Not : public UnaryOperator
{
public:
    Not();
    Not(Term* operand);

    Term* getCopy() const;
    std::string getType() const;

    Term* simplification() const;
};

#endif // NOT_H
