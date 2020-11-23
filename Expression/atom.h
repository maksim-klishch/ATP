#ifndef ATOM_H
#define ATOM_H

#include "variable.h"

class Atom : public Variable
{
    std::string _desc;
public:
    Atom();
    Atom(std::string name);
    Atom(std::string name, std::string desc);

    std::string getDescription();
    void setDescription(std::string desc);

    Term* getCopy() const;
    std::string getType() const;

    Term* simplification() const;
};

#endif // CONST_H
