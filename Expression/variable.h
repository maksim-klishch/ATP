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

    virtual bool getValue() const {return 1;}

    virtual std::string toString() const;
    virtual std::string getName() const;

    virtual std::string getType() const;
};

#endif // VARIABLE_H
