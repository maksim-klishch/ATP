#include "const.h"

Const::Const()
{

}

Const::Const(std::string name) : Variable(name)
{

}

Const::Const(std::string name, std::string desc) : Const(name)
{
    _desc = desc;
}

std::string Const::getDescription()
{
    return _desc;
}

void Const::setDescription(std::string desc)
{
    _desc = desc;
}
