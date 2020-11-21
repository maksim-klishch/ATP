#ifndef VARIABLESREGISTER_H
#define VARIABLESREGISTER_H

#include <map>

#include "variable.h"

class VariablesRegister
{
    std::map<std::string, Variable*> variables;
public:
    VariablesRegister();

    void addVariable(Variable* var);
    Variable* getVariable(std::string name);
};

#endif // VARIABLESREGISTER_H
