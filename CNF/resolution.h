#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <list>

#include "CNF/cnf.h"
#include "Expression/term.h"

class Resolution
{
    std::list<CNF> _cnfs;

    void convertToCNF(const Term* term, CNF& cnf);
public:
    Resolution();

    void addCNF(const CNF& cnf);
    void addCNF(const Term* term);
    bool proof() const;
};

#endif // RESOLUTION_H
