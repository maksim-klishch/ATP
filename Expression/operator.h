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

    virtual void setLeftTerm(Term* term);
    virtual void setRightTerm(Term* term);
    virtual void setTerms(Term* left, Term* right);

    virtual std::string toString() const;
};

#endif // OPERATOR_H
