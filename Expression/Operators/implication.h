#ifndef IMPLICATION_H
#define IMPLICATION_H

#include "Expression/binaryoperator.h"

class Implication : public BinaryOperator
{
public:
    Implication();
    Implication(Term* left, Term* right);

    Term* getCopy() const;
    std::string getType() const;
    unsigned short getPredenceLevel() const;

    Term* simplification() const;
};

#endif // IMPLICATION_H
