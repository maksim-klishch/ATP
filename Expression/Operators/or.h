#ifndef OR_H
#define OR_H

#include "Expression/binaryoperator.h"

class OR : public BinaryOperator
{
public:
    OR();
    OR(Term* left, Term* right);

    std::string toString() const;

    Term* getCopy() const;
    std::string getType() const;
    unsigned short getPredenceLevel() const;

    Term* simplification() const;
};

#endif // OR_H
