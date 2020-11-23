#include "and.h"

AND::AND()
{

}

AND::AND(Term* left, Term* right) : BinaryOperator(left, right)
{

}

Term *AND::getCopy() const
{
    return new AND(left->getCopy(), right->getCopy());
}

std::string AND::getType() const
{
    return "AND";
}

unsigned short AND::getPredenceLevel() const
{
    return 1;
}

Term *AND::simplification() const
{
    return new AND(left->simplification(), right->simplification());
}
