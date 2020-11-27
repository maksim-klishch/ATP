#include "not.h"
#include "or.h"
#include "and.h"

Not::Not()
{

}

Not::Not(Term *operand) : UnaryOperator(operand)
{

}

Term *Not::getCopy() const
{
    return new Not(getOperand());
}

std::string Not::getType() const
{
    return "NOT";
}

Term *Not::simplification() const
{
    Term* tmp = operand->simplification();

    if(tmp->getType() == "NOT") return ((UnaryOperator*)tmp)->getOperand();

    if(tmp->getType() == "AND")
    {
        Term* left =  (Not(((BinaryOperator*)tmp)->getLeftOperand())).simplification();
        Term* right = (Not(((BinaryOperator*)tmp)->getRightOperand())).simplification();
        delete tmp;
        return new Or(left, right);
    }

    if(tmp->getType() == "OR")
    {
        Term* left =  Not(((BinaryOperator*)tmp)->getLeftOperand()).simplification();
        Term* right = Not(((BinaryOperator*)tmp)->getRightOperand()).simplification();
        delete tmp;
        return new And(left, right);
    }

    return new Not(tmp);
}
