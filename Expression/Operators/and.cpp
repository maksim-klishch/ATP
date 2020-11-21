#include "and.h"

AND::AND()
{

}

bool AND::getValue() const
{
    return left->getValue() && right->getValue();
}

std::string AND::getType() const
{
    return "AND";
}

unsigned short AND::getPredenceLevel() const
{
    return 1;
}
