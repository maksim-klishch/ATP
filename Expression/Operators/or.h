#ifndef OR_H
#define OR_H

#include "Expression/operator.h"

class OR : public Operator
{
    const unsigned short predenceLevel = 2;
public:
    OR();

    bool getValue() const;
    std::string toString() const;

    std::string getType() const;
    unsigned short getPredenceLevel() const;
};

#endif // OR_H
