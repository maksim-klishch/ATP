#include "or.h"
#include "and.h"

OR::OR()
{

}

OR::OR(Term* left, Term* right) : BinaryOperator(left, right)
{

}

std::string OR::toString() const
{
    return (left ? left->toString() : "") + " OR " + (right ? right->toString() : "");
}

Term *OR::getCopy() const
{
    return new OR(left->getCopy(), right->getCopy());
}

std::string OR::getType() const
{
    return "OR";
}

unsigned short OR::getPredenceLevel() const
{
    return 2;
}

Term *OR::simplification() const
{
    Term* tmpLeft = left->simplification();
    Term* tmpRight = right->simplification();

    if(tmpRight->getType() == "AND")
    {
        Term* leftRes = (new OR(tmpLeft, ((BinaryOperator*)tmpRight)->getLeftOperand()))->simplification();
        Term* rightRes = (new OR(tmpLeft, ((BinaryOperator*)tmpRight)->getRightOperand()))->simplification();
        return new AND(leftRes, rightRes);
    }

    if(tmpLeft->getType() == "AND")
    {
        Term* leftRes = (new OR(((BinaryOperator*)tmpLeft)->getLeftOperand(), tmpRight))->simplification();
        Term* rightRes = (new OR(((BinaryOperator*)tmpLeft)->getRightOperand(), tmpRight))->simplification();
        return new AND(leftRes, rightRes);
    }

    return new OR(tmpLeft, tmpRight);
}
