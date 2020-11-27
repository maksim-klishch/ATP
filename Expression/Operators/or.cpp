#include "or.h"
#include "and.h"

Or::Or()
{

}

Or::Or(Term* left, Term* right) : BinaryOperator(left, right)
{

}

std::string Or::toString() const
{
    return (left ? left->toString() : "") + " Or " + (right ? right->toString() : "");
}

Term *Or::getCopy() const
{
    return new Or(getLeftOperand(), getRightOperand());
}

std::string Or::getType() const
{
    return "OR";
}

unsigned short Or::getPredenceLevel() const
{
    return 2;
}

Term *Or::simplification() const
{
    Term* tmpLeft = left->simplification();
    Term* tmpRight = right->simplification();

    if(tmpRight->getType() == "AND")
    {
        Term* leftRes = Or(tmpLeft->getCopy(), ((BinaryOperator*)tmpRight)->getLeftOperand()).simplification();
        Term* rightRes = Or(tmpLeft->getCopy(), ((BinaryOperator*)tmpRight)->getRightOperand()).simplification();
        delete tmpLeft;
        delete tmpRight;
        return new And(leftRes, rightRes);
    }

    if(tmpLeft->getType() == "AND")
    {
        Term* leftRes = Or(((BinaryOperator*)tmpLeft)->getLeftOperand(), tmpRight->getCopy()).simplification();
        Term* rightRes = Or(((BinaryOperator*)tmpLeft)->getRightOperand(), tmpRight->getCopy()).simplification();
        delete tmpLeft;
        delete tmpRight;
        return new And(leftRes, rightRes);
    }

    return new Or(tmpLeft, tmpRight);
}
