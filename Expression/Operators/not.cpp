#include "not.h"
#include "or.h"
#include "and.h"

NOT::NOT()
{

}

NOT::NOT(Term *operand) : UnaryOperator(operand)
{

}

Term *NOT::getCopy() const
{
    return new NOT(operand->getCopy());
}

std::string NOT::getType() const
{
    return "NOT";
}

Term *NOT::simplification() const
{
    Term* tmp = operand->simplification();

    if(tmp->getType() == "NOT") return ((UnaryOperator*)tmp)->getOperand();

    if(tmp->getType() == "AND")
    {
        Term* left =  (new NOT(((BinaryOperator*)tmp)->getLeftOperand()))->simplification();
        Term* right = (new NOT(((BinaryOperator*)tmp)->getRightOperand()))->simplification();
        return new OR(left, right);
    }

    if(tmp->getType() == "OR")
    {
        Term* left =  (new NOT(((BinaryOperator*)tmp)->getLeftOperand()))->simplification();
        Term* right = (new NOT(((BinaryOperator*)tmp)->getRightOperand()))->simplification();
        return new AND(left, right);
    }

    return new NOT(tmp);
}
