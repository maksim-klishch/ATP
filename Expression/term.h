#ifndef TERM_H
#define TERM_H

#include <string>
#include <list>

class Term
{
protected:
public:
    Term();
    virtual ~Term();

    virtual std::string toString() const = 0;

    virtual Term* getCopy() const = 0;
    virtual std::string getType() const = 0; //return the type of term (for example: var, and, or...)
    virtual unsigned short getPredenceLevel() const; //get predence level

    virtual Term* simplification() const = 0;
};

#endif // TERM_H
