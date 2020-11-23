#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <map>
#include <functional>

#include "Expression/term.h"
#include "Expression/variablesregister.h"
#include "Expression/atom.h"
#include "Expression/expression.h"

class Interpreter
{
    VariablesRegister varReg;
    std::map<std::string, std::function<Term*()>> operatorsFactory;
    std::list<std::string> keyword;

    void setSpaces(std::string& command, std::string str); //find str in command and set spaces before and after str
    void prepareToTokenize(std::string& command);
    void tokenize(std::string command, std::vector<std::string>& tokens);
    std::string translateOneCommand(std::string command);
    std::stack<std::string> toPolishReverseNotation(std::vector<std::string>& tokens);
    Term* toExpressionTree(std::vector<std::string>& tokens);
    Term* toExpressionTree(std::stack<std::string>& polishReverseNotation);
public:
    Interpreter();

    std::string interprete(std::string commands);
};

#endif // INTERPRETER_H
