#include "interpreter.h"

#include "Expression/Operators/and.h"
#include "Expression/Operators/not.h"
#include "Expression/Operators/or.h"
#include "Expression/Operators/implication.h"

#include "CNF/resolution.h"

#define AND         "AND"
#define OR          "OR"
#define NOT         "NOT"
#define IMPLICATION "IMPLICATION"

void Interpreter::setSpaces(std::string &command, const std::string &str)
{
    size_t pos = 0;
    while((pos = command.find(str, pos)) < command.size())
    {
        command = (pos != 0 ? command.substr(0, pos) + " " : "") + command.substr(pos, 1)
                + (pos != command.size() - 1 ? " " +  command.substr(pos + 1) : "");
        pos += str.size() + 1;
    }
}

void Interpreter::replaceAll(std::string &command, const std::string &str, const std::string &replace)
{
    size_t pos = 0;

    while((pos = command.find(str, pos)) < command.size())
    {
        command.replace(pos, str.size(), replace);
        pos += str.size();
    }
}

void Interpreter::prepareToTokenize(std::string &command)
{
    size_t pos = command.find_first_not_of(" ");
    command.erase(0, pos);

    setSpaces(command, "(");
    setSpaces(command, ")");
    setSpaces(command, "=");
    setSpaces(command, ",");

    replaceAll(command, "->", " IMPLICATION ");
    replaceAll(command, "  ", " ");
}

void Interpreter::tokenize(std::string& command, std::vector<std::string> &tokens)
{
    size_t pos;

    prepareToTokenize(command);

    while((pos = command.find(" ")) < command.size())
    {
        tokens.push_back(command.substr(0, pos));
        command.erase(0, pos + 1);
    }
    if(command.size()) tokens.push_back(command);
}

std::string Interpreter::translateOneCommand(std::string command)
{
    std::vector<std::string> tokens;
    tokenize(command, tokens);

    if(!tokens.size()) return "";

    if(tokens[0] == "atom")
    {
        if(tokens.size() < 3) throw "Error: Invalid format.";
        if(varReg.hasElement(tokens[1])) throw "Error: Multiple definition of " + tokens[1] + ".";

        std::string desc = "";
        for(unsigned int i = 2; i < tokens.size(); ++i)
        {
            desc += tokens[i] + " ";
        }

        varReg.addElement(tokens[1], new Atom(tokens[1], desc));
    }
    else if(tokens[0] == "molecule")
    {
        if(tokens[2] != "=" or tokens.size() < 4) throw "Error: Invalid format.";
        if(varReg.hasElement(tokens[1])) throw "Error: Multiply definition of " + tokens[1] + ".";

        std::vector<std::string> expressionTokens(tokens.begin() + 3, tokens.end());
        varReg.addElement(tokens[1], new Expression(tokens[1], toExpressionTree(expressionTokens)));
    }
    else if(tokens[0] == "proof")
    {
        Resolution resolution;
        std::vector<std::string> expressionTokens;
        bool isResolvent = false;

        for(unsigned int i = 1; i <= tokens.size(); ++i)
        {
            if(i == tokens.size() || tokens[i] == "," || tokens[i] == "|-")
            {
                if(expressionTokens.size() == 0) throw "Error: Invalid syntax.";
                Term* term = toExpressionTree(expressionTokens);
                if(isResolvent) term = new Not(term);

                resolution.addCNF(term);

                delete term;
                expressionTokens.clear();

                if(i != tokens.size() && tokens[i] == "|-") isResolvent = true;
            }
            else expressionTokens.push_back(tokens[i]);
        }

        return (resolution.proof() ? "true\n" : "false\n");
    }
    else
    {
        throw "Error: Unknown syntax.";
    }

    return "";
}

std::stack<std::string> Interpreter::toPolishReverseNotation(std::vector<std::string> &tokens)
{
    std::stack<std::string> resStack;
    std::stack<std::string> opStack;

    unsigned short variablesCount = 0, binaryOperatorsCount = 0, unaryOperatorsCount = 0;

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

        if(operReg.hasElement(tokens[i]))
        {
            while(!opStack.empty() && operReg.hasElement(opStack.top()))
            {
                if(operReg.getElement(tokens[i])->getPredenceLevel() > operReg.getElement(opStack.top())->getPredenceLevel())
                {
                    resStack.push(opStack.top());
                    opStack.pop();
                }
                else break;
            }

            if(tokens[i] != NOT) ++binaryOperatorsCount;
            else ++unaryOperatorsCount;

            opStack.push(tokens[i]);

            continue;
        }

        ++variablesCount;
        resStack.push(tokens[i]);
    }

    while(!opStack.empty())
    {
        if(opStack.top() == "(") throw "Error: Expected \')\' token.";
        resStack.push(opStack.top());
        opStack.pop();
    }

    if(variablesCount != binaryOperatorsCount + 1 || unaryOperatorsCount >= 2 * variablesCount)
        throw "Error: Incorrect syntax";

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

    if(operReg.hasElement(current))
    {
        Term* res = operReg.getElement(current)->getCopy();

        if(res->getType() == NOT)
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

    if(!varReg.hasElement(current)) throw "Error: Variable " + current + " isn\'t defined.";
    return varReg.getElement(current)->getCopy();
}

Interpreter::Interpreter()
{
    operReg.addElement(AND, new And());
    operReg.addElement(NOT, new Not());
    operReg.addElement(OR, new Or());
    operReg.addElement(IMPLICATION, new Implication());
}

std::string Interpreter::interprete(std::string commands)
{
    std::string result = "";

    try{
        size_t pos;
        while((pos = commands.find("\n")) < commands.size())
        {
            result += translateOneCommand(commands.substr(0, pos));
            commands.erase(0, pos + 1);
        }
        if(commands.size() > 0) result += translateOneCommand(commands);
    } catch(std::string exception) {
        return exception + "\n";
    } catch(const char* exception) {
        return exception;
    } catch(...){
        return "Error: Unknown problem.";
    }

    return result;
}
