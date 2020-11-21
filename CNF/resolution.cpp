#include "resolution.h"

Resolution::Resolution()
{

}

void Resolution::addCNF(const CNF &cnf)
{
    std::list<CNF>::const_iterator iter;

    for(iter = _cnfs.begin(); iter != _cnfs.end(); ++iter)
    {
        if(*iter == cnf) return;
    }

    for(iter = _cnfs.begin(); iter != _cnfs.end(); ++iter)
    {
        if(CNF::canUseResolutionRule(*iter, cnf))
        {
            addCNF(CNF::split(*iter, cnf));
        }
    }

    _cnfs.push_back(cnf);
}

bool Resolution::proof() const
{
    std::list<CNF>::const_iterator iter;
    for(iter = _cnfs.begin(); iter != _cnfs.end(); ++iter)
    {
        if(iter->isEmpty()) return true;
    }

    return false;
}
