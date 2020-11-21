#include "atom.h"

Atom::Atom()
{

}

Atom::Atom(std::string name) : Variable(name)
{

}

Atom::Atom(std::string name, std::string desc) : Atom(name)
{
    _desc = desc;
}

std::string Atom::getDescription()
{
    return _desc;
}

void Atom::setDescription(std::string desc)
{
    _desc = desc;
}

std::string Atom::getType() const
{
    return "Atom";
}
