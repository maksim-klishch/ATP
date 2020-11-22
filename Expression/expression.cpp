#include "expression.h"

Expression::Expression(std::string name) : Variable(name)
{
}

Expression::Expression(std::string name, Term *term) : Expression(name)
{
    _term = term;
}

std::string Expression::getType() const
{
    return "Expression";
}

std::string Expression::toString() const
{
    return _term->toString();
}
