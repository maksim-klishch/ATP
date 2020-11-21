#ifndef TERM_H
#define TERM_H

#include <string>

class Term
{
public:
    Term();

    virtual bool getValue() const = 0;
    virtual std::string toString() const = 0;
};

#endif // TERM_H
