#ifndef AND_H
#define AND_H

#include "Expression/binaryoperator.h"

class AND : public BinaryOperator
{
public:
    AND();
    AND(Term* left, Term* right);

    Term* getCopy() const;
    std::string getType() const;
    unsigned short getPredenceLevel() const;

    Term* simplification() const;
};

#endif // AND_H
