#include "and.h"

AND::AND()
{

}

bool AND::getValue() const
{
    return left->getValue() && right->getValue();
}

std::string AND::toString() const
{
    return (left ? left->toString() : "") + " AND " + (right ? right->toString() : "");
}
