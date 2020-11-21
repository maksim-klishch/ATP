#include "cnf.h"

CNF::CNF()
{

}

CNF::CNF(const CNF &obj)
{
    this->variables.insert(obj.variables.begin(), obj.variables.end());
}

void CNF::addVariable(std::string name, bool negation)
{
    if(!hasVariable(name))
        this->variables.insert(std::pair<std::string, bool>(name, negation));
    else if(variables.at(name) != negation) this->variables.erase(variables.find(name));
}

bool CNF::hasVariable(std::string name) const
{
    return variables.find(name) != variables.end();
}

bool CNF::getVariable(std::string name) const
{
    if(hasVariable(name)) return variables.at(name);
    return 0;
}

bool CNF::isEmpty() const
{
    return variables.size() == 0;
}

unsigned short CNF::getVariablesCount() const
{
    return variables.size();
}

CNF CNF::split(const CNF& a, const CNF& b)
{
    CNF res;
    std::map<std::string, bool>::const_iterator iter;

    for(iter = a.variables.begin(); iter != a.variables.end(); ++iter)
    {
        res.addVariable(iter->first, iter->second);
    }

    for(iter = b.variables.begin(); iter != b.variables.end(); ++iter)
    {
        res.addVariable(iter->first, iter->second);
    }

    return res;
}

bool CNF::canUseResolutionRule(const CNF &a, const CNF &b)
{
    std::map<std::string, bool>::const_iterator iter;

    for(iter = a.variables.begin(); iter != a.variables.end(); ++iter)
    {
        if(b.hasVariable(iter->first))
        {
            if(b.getVariable(iter->first) != iter->second) return true;
        }
    }

    return false;
}

bool CNF::operator ==(const CNF &obj) const
{
    std::map<std::string, bool>::const_iterator iter;
    for(iter = variables.begin(); iter != variables.end(); ++iter)
    {
        if(!obj.hasVariable(iter->first)) return false;
        else if(obj.getVariable(iter->first) != iter->second) return false;
    }

    return this->getVariablesCount() == obj.getVariablesCount();
}

bool CNF::operator !=(const CNF &obj) const
{
    return !(*this == obj);
}
