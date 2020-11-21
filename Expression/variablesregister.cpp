#include <iostream>

#include "variablesregister.h"

VariablesRegister::VariablesRegister()
{

}

void VariablesRegister::addVariable(Variable *var)
{
    if(variables.find(var->getName()) == variables.end())
    {
        variables.insert(std::pair<std::string, Variable*>(var->getName(), var));
        return;
    }

    std::cerr << "Variable with this name is defined." << std::endl;
}

Variable* VariablesRegister::getVariable(std::string name)
{
    if(variables.find(name) == variables.end()) return nullptr;
    return variables[name];
}
