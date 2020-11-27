#include "implication.h"

#include "or.h"
#include "not.h"

Implication::Implication()
{

}

Implication::Implication(Term *left, Term *right) : BinaryOperator(left, right)
{
}

Term *Implication::getCopy() const
{
    return new Implication(getLeftOperand(), getRightOperand());
}

std::string Implication::getType() const
{
    return "IMPLICATION";
}

unsigned short Implication::getPredenceLevel() const
{
    return 3;
}

Term *Implication::simplification() const
{
    return Or(new Not(getLeftOperand()), getRightOperand()).simplification();
}


