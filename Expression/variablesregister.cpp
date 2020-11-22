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
    if(hasVariable(name)) return variables[name];
    return nullptr;
}

bool VariablesRegister::hasVariable(std::string name)
{
    return variables.find(name) != variables.end();
}
