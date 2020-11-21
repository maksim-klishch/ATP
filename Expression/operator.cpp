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
