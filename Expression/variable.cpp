#include "variable.h"

Variable::Variable()
{

}

Variable::Variable(std::string name) : _name(name)
{

}

Variable::~Variable()
{

}

std::string Variable::toString() const
{
    return _name;
}

std::string Variable::getName() const
{
    return _name;
}
