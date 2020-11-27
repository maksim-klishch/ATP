#include "and.h"

And::And()
{

}

And::And(Term* left, Term* right) : BinaryOperator(left, right)
{

}

Term *And::getCopy() const
{
    return new And(getLeftOperand(), getRightOperand());
}

std::string And::getType() const
{
    return "AND";
}

unsigned short And::getPredenceLevel() const
{
    return 1;
}

Term *And::simplification() const
{
    return new And(left->simplification(), right->simplification());
}
