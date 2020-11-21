#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "term.h"

class UnaryOperator : public Term
{
protected:
    Term* term;
public:
    void setTerm(Term* term);

    virtual std::string toString() const;
};

#endif // UNARYOPERATOR_H
