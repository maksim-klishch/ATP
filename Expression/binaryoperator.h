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

    virtual void setLeftTerm(Term* term);
    virtual void setRightTerm(Term* term);
    virtual void setTerms(Term* left, Term* right);

    virtual std::string toString() const;
};

#endif //BINARYOPERATOR_H
