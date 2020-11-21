#include "binaryoperator.h"

BinaryOperator::BinaryOperator()
{

}

BinaryOperator::BinaryOperator(Term *left, Term *right)
{
    this->left = left;
    this->right = right;
}

BinaryOperator::~BinaryOperator()
{
    //if(left) delete left;
    //if(right) delete right;
}

void BinaryOperator::setLeftTerm(Term *term)
{
    left = term;
}

void BinaryOperator::setRightTerm(Term *term)
{
    right = term;
}

void BinaryOperator::setTerms(Term *left, Term *right)
{
    this->setLeftTerm(left);
    this->setRightTerm(right);
}

std::string BinaryOperator::toString() const
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
