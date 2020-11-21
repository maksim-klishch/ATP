#ifndef CONST_H
#define CONST_H

#include "variable.h"

class Const : public Variable
{
    std::string _desc;
public:
    Const();
    Const(std::string name);
    Const(std::string name, std::string desc);

    std::string getDescription();
    void setDescription(std::string desc);
};

#endif // CONST_H
