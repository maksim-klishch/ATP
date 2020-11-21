#ifndef AND_H
#define AND_H

#include "Expression/operator.h"

class AND : public Operator
{
public:
    AND();

    bool getValue() const;
    std::string getType() const;
    unsigned short getPredenceLevel() const;
};

#endif // AND_H
