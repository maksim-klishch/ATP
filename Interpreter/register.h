#ifndef REGISTER_H
#define REGISTER_H

#include <map>
#include <string>
#include <iostream>

template <class T>
class Register
{
protected:
    std::map<std::string, T*> elements;
public:

    ~Register()
    {
        for(auto iter = elements.begin(); iter != elements.end(); ++iter)
        {
            if(iter->second != nullptr) delete iter->second;
        }

        elements.clear();
    }

    void addElement(std::string name, T* element)
    {
        if(!hasElement(name))
        {
            elements.insert(std::pair<std::string, T*>(name, element));
            return;
        }

        std::cerr << "Element with name " << name << " is defined." << std::endl;
    }

    T* getElement(std::string name)
    {
        if(hasElement(name)) return elements[name];
        return nullptr;
    }

    bool hasElement(std::string name) const
    {
        return elements.find(name) != elements.end();
    }
};

#endif // REGISTER_H
