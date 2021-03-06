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
    virtual ~Variable();

    virtual std::string toString() const;
    virtual std::string getName() const;
};

#endif // VARIABLE_H
