#ifndef CNF_H
#define CNF_H

#include <map>
#include <utility>
#include <string>
#include <vector>

#include <iostream>

class CNF
{
    std::map<std::string, bool> variables;

public:
    CNF();
    CNF(const CNF& obj);

    void addVariable(std::string name, bool negation);
    bool hasVariable(std::string name) const;
    bool getVariable(std::string name) const;
    bool isEmpty() const;
    unsigned short getVariablesCount() const;

    static CNF split(const CNF& a, const CNF& b);

    //check if there are same variables in CNFs, but different in negation
    static bool canUseResolutionRule(const CNF& a, const CNF& b);

    void print() const //print list of variables to console
    {
        std::map<std::string, bool>::const_iterator iter;
        for(iter = variables.begin(); iter != variables.end(); ++iter)
        {
            std::cout << (iter->second ? "~" : "") << iter->first << std::endl;
        }
    }

    bool operator ==(const CNF& obj) const;
    bool operator !=(const CNF& obj) const;
};

#endif // CNF_H
