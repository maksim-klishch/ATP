#include "unaryoperator.h"

UnaryOperator::UnaryOperator()
{
    operand = nullptr;
}

UnaryOperator::UnaryOperator(Term *operand)
{
    setOperand(operand);
}

UnaryOperator::~UnaryOperator()
{
    if(operand) delete operand;
}

void UnaryOperator::setOperand(Term *operand)
{
    this->operand = operand;
}

Term *UnaryOperator::getOperand() const
{
    if(!operand) return nullptr;
    return operand->getCopy();
}

std::string UnaryOperator::toString() const
{
    std::string res = getType();
    if(operand)
    {
        if(operand->getType() == "Atom") res += " " + operand->toString();
        else res += " (" + operand->toString() + ")";
    }
    return res;
}
