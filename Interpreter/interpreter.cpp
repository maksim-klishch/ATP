#include "interpreter.h"

#include "Expression/Operators/and.h"
#include "Expression/Operators/not.h"
#include "Expression/Operators/or.h"

#include "CNF/resolution.h"

void Interpreter::setSpaces(std::string &command, std::string str)
{
    size_t pos;
    size_t f = 0;
    while((pos = command.find_first_of(str, f)) < command.size())
    {
        command = (pos != 0 ? command.substr(0, pos) + " " : "") + command.substr(pos, 1)
                + (pos != command.size() - 1 ? " " +  command.substr(pos + 1) : "");
        f = pos + 2;
    }
}

void Interpreter::prepareToTokenize(std::string &command)
{
    size_t pos = command.find_first_not_of(" ");
    command.erase(0, pos);

    setSpaces(command, "(");
    setSpaces(command, ")");
    setSpaces(command, "=");

    while((pos = command.find("  ")) < command.size())
    {
        command.erase(pos, 1);
    }
}

void Interpreter::tokenize(std::string command, std::vector<std::string> &tokens)
{
    size_t pos;

    prepareToTokenize(command);

    while((pos = command.find(" ")) < command.size())
    {
        tokens.push_back(command.substr(0, pos));
        command.erase(0, pos + 1);
    }
    tokens.push_back(command);
}

std::string Interpreter::translateOneCommand(std::string command)
{
    std::vector<std::string> tokens;
    tokenize(command, tokens);

    if(!tokens.size()) return "";

    if(tokens[0] == "atom")
    {
        if(tokens.size() < 3) throw "Error: Invalid format.";
        if(varReg.hasVariable(tokens[1])) throw "Error: Multiple definition of " + tokens[1] + ".";

        std::string desc = "";
        for(unsigned int i = 2; i < tokens.size(); ++i)
        {
            desc += tokens[i];
        }

        varReg.addVariable(new Atom(tokens[1], desc));
    }

    if(tokens[0] == "molecule")
    {
        if(tokens[2] != "=" or tokens.size() < 4) throw "Error: Invalid format.";
        if(varReg.hasVariable(tokens[1])) throw "Error: Multiply definition of " + tokens[1] + ".";

        std::vector<std::string> expressionTokens(tokens.begin() + 3, tokens.end());
        varReg.addVariable(new Expression(tokens[1], toExpressionTree(expressionTokens)));
    }

    return "";
}

std::stack<std::string> Interpreter::toPolishReverseNotation(std::vector<std::string> &tokens)
{
    std::stack<std::string> resStack;
    std::stack<std::string> opStack;

    std::map<std::string, unsigned int> operators;
    operators.insert(std::pair<std::string, unsigned int>("NOT", 0));
    operators.insert(std::pair<std::string, unsigned int>("AND", 1));
    operators.insert(std::pair<std::string, unsigned int>("OR", 2));

    for(unsigned int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == "(")
        {
            opStack.push(tokens[i]);
            continue;
        }

        if(tokens[i] == ")")
        {
            if(opStack.empty()) throw "Error: Expected '\(\' token.";
            while(!opStack.empty() && opStack.top() != "(")
            {
                resStack.push(opStack.top());
                opStack.pop();
            }

            if(opStack.top() != "(") throw "Error: Expected '\(\' token.";
            opStack.pop();

            continue;
        }

        if(operators.find(tokens[i]) != operators.end())
        {
            while(!opStack.empty() && operators.find(opStack.top()) != operators.end())
            {
                if(operators[tokens[i]] > operators[opStack.top()])
                {
                    resStack.push(opStack.top());
                    opStack.pop();
                }
                else break;
            }

            opStack.push(tokens[i]);

            continue;
        }

        resStack.push(tokens[i]);
    }

    while(!opStack.empty())
    {
        if(opStack.top() == "(") throw "Error: Expected \')\' token.";
        resStack.push(opStack.top());
        opStack.pop();
    }

    return resStack;
}

Term* Interpreter::toExpressionTree(std::vector<std::string> &tokens)
{
    std::stack<std::string> polishReverseNotation;
    polishReverseNotation = toPolishReverseNotation(tokens);
    return toExpressionTree(polishReverseNotation);
}

Term *Interpreter::toExpressionTree(std::stack<std::string> &polishReverseNotation)
{
    if(polishReverseNotation.empty()) throw "Error: Invalid format.";

    std::string current = polishReverseNotation.top();
    polishReverseNotation.pop();

    if(operatorsFactory.find(current) != operatorsFactory.end())
    {
        Term* res = operatorsFactory[current]();

        if(res->getType() == "NOT")
        {
            ((UnaryOperator*)res)->setOperand(toExpressionTree(polishReverseNotation));
        }
        else
        {
            ((BinaryOperator*)res)->setRightOperand(toExpressionTree(polishReverseNotation));
            ((BinaryOperator*)res)->setLeftOperand(toExpressionTree(polishReverseNotation));
        }

        return res;
    }

    if(!varReg.hasVariable(current)) throw "Error: Variable " + current + " isn\'t defined.";
    return varReg.getVariable(current);
}

Interpreter::Interpreter()
{
    operatorsFactory.insert(std::pair<std::string, std::function<Term*()>>("NOT", [](){return new NOT();}));
    operatorsFactory.insert(std::pair<std::string, std::function<Term*()>>("AND", [](){return new AND();}));
    operatorsFactory.insert(std::pair<std::string, std::function<Term*()>>("OR",  [](){return new OR();}));
}

std::string Interpreter::interprete(std::string commands)
{
    std::string result = "";

    try{
        size_t pos;
        while((pos = commands.find("\n")) < commands.size())
        {
            translateOneCommand(commands.substr(0, pos));
            commands.erase(0, pos + 1);
        }
        if(commands.size() > 0) translateOneCommand(commands);
    } catch(std::string exception) {
        return exception + "\n";
    }

    Term* F1 = new OR(new Atom("A"), new OR(new Atom("B"), new Atom("C")));
    Term* F2 = new OR(new Atom("A"), new OR(new NOT(new Atom("B")), new Atom("C")));
    Term* F3 = new NOT(new Atom("C"));
    Term* P = new Atom("C");

    Resolution resolt;
    resolt.addCNF(F1);
    resolt.addCNF(F2);
    resolt.addCNF(F3);
    resolt.addCNF(P);

    std::cout << resolt.proof() << std::endl;

    return result;
}
