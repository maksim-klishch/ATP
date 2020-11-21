#ifndef TERM_H
#define TERM_H

#include <string>
#include <list>

#include "CNF/cnf.h"

class Term
{
protected:
public:
    Term();

    virtual bool getValue() const = 0;
    virtual std::string toString() const = 0;

    virtual std::string getType() const; //return the type of term (for example: var, and, or...)
    virtual unsigned short getPredenceLevel() const; //get predence level
};

#endif // TERM_H
