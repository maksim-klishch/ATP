#ifndef AND_H
#define AND_H

#include "Expression/operator.h"

class AND : public Operator
{
public:
    AND();

    bool getValue() const;
    std::string toString() const;
};

#endif // AND_H
