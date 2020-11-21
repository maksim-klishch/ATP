#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "term.h"

class Variable : public Term
{
protected:
    std::string _name;
public:
    Variable();
    Variable(std::string name);

    bool getValue() const {return 1;}

    std::string toString() const;
    std::string getName() const;
};

#endif // VARIABLE_H
