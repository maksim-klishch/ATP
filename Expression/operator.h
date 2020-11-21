#ifndef OPERATOR_H
#define OPERATOR_H

#include <vector>

#include "term.h"

class Operator : public Term
{
protected:
    Term *left, *right;
public:
    Operator();

    virtual ~Operator();

    void setLeftTerm(Term* term);
    void setRightTerm(Term* term);
    void setTerms(Term* left, Term* right);
};

#endif // OPERATOR_H
