#include "or.h"

OR::OR()
{

}

bool OR::getValue() const
{
    return left->getValue() || right->getValue();
}

std::string OR::toString() const
{
    return (left ? left->toString() : "") + " OR " + (right ? right->toString() : "");
}

std::string OR::getType() const
{
    return "OR";
}

unsigned short OR::getPredenceLevel() const
{
    return 2;
}
