#include "operator.h"

Operator::Operator()
{

}

Operator::~Operator()
{
    //if(left) delete left;
    //if(right) delete right;
}

void Operator::setLeftTerm(Term *term)
{
    left = term;
}

void Operator::setRightTerm(Term *term)
{
    right = term;
}

void Operator::setTerms(Term *left, Term *right)
{
    this->setLeftTerm(left);
    this->setRightTerm(right);
}

std::string Operator::toString() const
{
    std::string res = "";

    if(left)
    {
        if(this->getPredenceLevel() < left->getPredenceLevel()) res += "(" + left->toString() + ")";
        else res += left->toString();
    }

    res += " " + this->getType() + " ";

    if(right)
    {
        if(this->getPredenceLevel() < right->getPredenceLevel()) res += "(" + right->toString() + ")";
        else res += right->toString();
    }

    return res;
}
