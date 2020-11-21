#include "unaryoperator.h"

void UnaryOperator::setTerm(Term *term)
{
    this->term = term;
}

std::string UnaryOperator::toString() const
{
    std::string res = getType();
    if(term)
    {
        if(term->getType() == "Atom") res += " " + term->toString();
        else res += " (" + term->toString() + ")";
    }
    return res;
}
