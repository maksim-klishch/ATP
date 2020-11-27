#include "resolution.h"

#include "Expression/binaryoperator.h"
#include "Expression/unaryoperator.h"
#include "Expression/variable.h"

void Resolution::convertToCNF(const Term *term, CNF& cnf)
{
    if(term->getType() == "OR")
    {
        convertToCNF(((BinaryOperator*)term)->getLeftOperand(), cnf);
        convertToCNF(((BinaryOperator*)term)->getRightOperand(), cnf);
        return;
    }

    if(term->getType() == "NOT")
    {
        cnf.addVariable(((Variable*)((UnaryOperator*)term)->getOperand())->getName(), 1);
        return;
    }

    cnf.addVariable(((Variable*)term)->getName(), 0);
}

Resolution::Resolution()
{

}

void Resolution::addCNF(const CNF &cnf)
{
    std::list<CNF>::const_iterator iter, end;
    end = _cnfs.end();

    for(iter = _cnfs.begin(); iter != end; ++iter)
    {
        if(*iter == cnf) return;
    }

    _cnfs.push_back(cnf);

    for(iter = _cnfs.begin(); iter != end; ++iter)
    {
        if(CNF::canUseResolutionRule(*iter, cnf))
        {
            addCNF(CNF::split(*iter, cnf));
        }
    }
}

void Resolution::addCNF(const Term *term)
{
    Term* simpleTerm = term->simplification();

    if(simpleTerm->getType() == "AND") {
        this->addCNF(((BinaryOperator*)simpleTerm)->getLeftOperand());
        this->addCNF(((BinaryOperator*)simpleTerm)->getRightOperand());
    } else {
        CNF cnf;
        convertToCNF(simpleTerm, cnf);
        this->addCNF(cnf);
    }

    delete simpleTerm;
}

bool Resolution::proof() const
{
    std::list<CNF>::const_iterator iter;
    for(iter = _cnfs.begin(); iter != _cnfs.end(); ++iter)
    {
        if(iter->isEmpty()) return true;
    }

    return false;
}
