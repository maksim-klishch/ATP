#ifndef NOT_H
#define NOT_H

#include "Expression/unaryoperator.h"

class NOT : public UnaryOperator
{
public:
    NOT();

    bool getValue() const {return !term->getValue();}
    std::string getType() const;
};

#endif // NOT_H
