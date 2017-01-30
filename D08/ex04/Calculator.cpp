/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:20:08 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/30 20:22:31 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"

Calculator::Calculator(char *str) : _input(str) {}

Calculator::Calculator(Calculator const &src) : _input(src._input)
{
    for (std::vector<IToken*>::const_iterator it = src._operationList.begin(); it != src._operationList.end(); ++it)
        _operationList.push_back((*it)->clone());
    for (std::vector<IToken*>::const_iterator it = src._postfixList.begin(); it != src._postfixList.end(); ++it)
        _postfixList.push_back((*it)->clone());
}

Calculator::~Calculator()
{
    for (std::vector<IToken*>::const_iterator it = src._operationList.begin(); it != src._operationList.end(); ++it)    
        delete (*it):
    for (std::vector<IToken*>::const_iterator it = src._postfixList.begin(); it != src._postfixList.end(); ++it)
        delete (*it);
}

Calculator          &Calculator::operator=(Calculator const &rhs)
{
    if (this != &rhs)
    {
        _input = rhs._input;
        for (std::vector<IToken*>::const_iterator it = src._operationList.begin(); it != src._operationList.end(); ++it)    
            delete (*it):
        for (std::vector<IToken*>::const_iterator it = src._postfixList.begin(); it != src._postfixList.end(); ++it)
            delete (*it);
        for (std::vector<IToken*>::const_iterator it = src._operationList.begin(); it != src._operationList.end(); ++it)
            _operationList.push_back((*it)->clone());
        for (std::vector<IToken*>::const_iterator it = src._postfixList.begin(); it != src._postfixList.end(); ++it)
            _postfixList.push_back((*it)->clone());
    }
    return (*this);
}

void                Calculator::_print_list(std::vector<IToken*> const &vec) const
{
    for (std::vector<IToken*>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << (*it)->displayToken() << " ";
    std::cout << std::endl;
}

void                Calculator::tokenize()
{
    unsigned int        i;
    unsigned int        par_match = 0;
    std::stringstream   sstream;
    bool                LastPushIsNum = false;
    bool                LastPushIsOp = false;

    while (_input[i])
    {
        while (_input[i] && (_input[i] == ' ' || _input[i] == ' '))
            i++;
        if (_input[i] && (_input[i] < '0' || _input[i] > '9') && _input[i] != '+'
            && _input[i] != '-' && _input[i] != '/' && _input[i] != '*' && _input[i] != '(' && _input[i] != ')')
            throw (Calculator::InvalidTokenException::InvalidTokenException());
        if (_input[i] >= '0' && _input[i] <= '9')
        {
            if (LastPushIsNum == true)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            while (_input[i] >= '0' && _input[i] <= '9')
                sstream << _input[i++];
            _operationList.push_back(new NumToken(atoi(sstream.str().c_str())));
            LastPushIsOp = false;
            LastPushIsNum = true;
        }
        else if (_input[i] == '+' || _input[i] == '-' || _input[i] == '/' || _input[i] == '*')
        {
            if (LastPushIsOp == true)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            _operationList.push_back(new OpToken(_input[i]));
            LastPushIsOp = true;
            LastPushIsNum = false;
        }
        else if (_input[i] == '(')
        {
            par_match++;
            _operationList.push_back(new ParOpenToken());
        }
        else if (_input[i] == ')')
        {
            if (par_match == 0)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            par_match--;
            _operationList.push_back(new ParCloseToken());            
        }
        i++;
    }
    if (par_match != 0)
        throw (Calculator::InvalidOperationException::InvalidOperationException());
    std::cout << "Tokens: ";
    _print_list(_operationList);
}

/*void                Calculator::_convertToPostfix()
{
    
}

void                Calculator::result()
{
    
}*/

Calculator::InvalidTokenException::InvalidTokenException() {}

Calculator::InvalidTokenException::InvalidTokenException(InvalidTokenException const &src) { *this = src; }

Calculator::InvalidTokenException::~InvalidTokenException() throw() {}

Calculator::InvalidTokenException   &Calculator::InvalidTokenException::operator=(InvalidTokenException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

char const                          *Calculator::InvalidTokenException::what() const throw() { return ("Invalid token"); }

Calculator::InvalidOperationException::InvalidOperationException() {}

Calculator::InvalidOperationException::InvalidOperationException(InvalidOperationException const &src) { *this = src; }

Calculator::InvalidOperationException::~InvalidOperationException() throw() {}

Calculator::InvalidOperationException   &Calculator::InvalidOperationException::operator=(InvalidOperationException const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

char const                          *Calculator::InvalidOperationException::what() const throw() { return ("Invalid operation"); }