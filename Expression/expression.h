#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "variable.h"

class Expression : public Variable
{
    Term* _term;
public:
    Expression(std::string name);
    Expression(std::string name, Term* term);
    ~Expression();

    Term* getCopy() const;
    std::string getType() const;
    std::string toString() const;

    Term* simplification() const;
};

#endif // EXPRESSION_H
