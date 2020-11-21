#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <list>
#include "CNF/cnf.h"

class Resolution
{
    std::list<CNF> _cnfs;
public:
    Resolution();

    void addCNF(const CNF& cnf);
    bool proof() const;
};

#endif // RESOLUTION_H
