#ifndef OR_H
#define OR_H

#include "Expression/operator.h"

class OR : public Operator
{
public:
    OR();

    bool getValue() const;
    std::string toString() const;
};

#endif // OR_H
