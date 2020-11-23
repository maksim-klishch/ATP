#include "expression.h"

Expression::Expression(std::string name) : Variable(name)
{
}

Expression::Expression(std::string name, Term *term) : Expression(name)
{
    _term = term;
}

Expression::~Expression()
{
    if(_term) delete _term;
}

Term *Expression::getCopy() const
{
    return new Expression(_name, _term->getCopy());
}

std::string Expression::getType() const
{
    return "Expression";
}

std::string Expression::toString() const
{
    return _term->toString();
}

Term *Expression::simplification() const
{
    if(!_term) return nullptr;
    return _term->simplification();
}
