#include "variable.h"

Variable::Variable()
{

}

Variable::Variable(std::string name) : _name(name)
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

std::string Variable::getType() const
{
    return "Var";
}
