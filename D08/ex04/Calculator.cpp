/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:20:08 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 20:52:48 by fsidler          ###   ########.fr       */
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
    for (std::vector<IToken*>::const_iterator it = _operationList.begin(); it != _operationList.end(); ++it)    
        delete (*it);
    for (std::vector<IToken*>::const_iterator it = _postfixList.begin(); it != _postfixList.end(); ++it)
        delete (*it);
}

Calculator          &Calculator::operator=(Calculator const &rhs)
{
    if (this != &rhs)
    {
        _input = rhs._input;
        for (std::vector<IToken*>::const_iterator it = _operationList.begin(); it != _operationList.end(); ++it)    
            delete (*it);
        for (std::vector<IToken*>::const_iterator it = _postfixList.begin(); it != _postfixList.end(); ++it)
            delete (*it);
        for (std::vector<IToken*>::const_iterator it = rhs._operationList.begin(); it != rhs._operationList.end(); ++it)
            _operationList.push_back((*it)->clone());
        for (std::vector<IToken*>::const_iterator it = rhs._postfixList.begin(); it != rhs._postfixList.end(); ++it)
            _postfixList.push_back((*it)->clone());
    }
    return (*this);
}

void                Calculator::_print_list(std::vector<IToken*> const &vec) const
{
    for (std::vector<IToken*>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        (*it)->display();
    std::cout << std::endl;
}

int		            Calculator::_my_atoi(const char *str, unsigned int *k)
{
	int		        s;
	int		        r;
    unsigned int    l = 0;
    bool            sign = false;

	r = 0;
	s = 1;
    while (str[*k] && str[*k] >= 0 && str[*k] <= 32)
		(*k)++;
	if (str[*k] == '-')
		s = -1;
	if (str[*k] == '+' || str[*k] == '-')
    {
        sign = true;
		(*k)++;
    }
	while (str[*k] && str[*k] >= '0' && str[*k] <= '9')
	{
		r = r * 10 + str[*k] - '0';
        l++;
		(*k)++;
	}
    if (sign == true || l != 0)
        (*k)--;
	return (s * r);
}

void                Calculator::tokenize()
{
    int                 num;
    int                 par_match = 0;
    unsigned int        i = 0;
    bool                LastPushIsNum = false;
    bool                LastPushIsOp = false;
    bool                LastPushIsParOpen = false;
    bool                LastPushIsParClose = false;
    
    while (i < strlen(_input))
    {
        if (_input[i] && (_input[i] < '0' || _input[i] > '9') && _input[i] != '+'
            && _input[i] != '-' && _input[i] != '/' && _input[i] != '*' && _input[i] != '(' && _input[i] != ')' && _input[i] != ' ' && _input[i] != 9)
            throw (Calculator::InvalidTokenException::InvalidTokenException());
        i++;
    }
    i = 0;
    while (i < strlen(_input))
    {
        num = 0;     
        if (_input[i] == '0' || (num = _my_atoi(_input, &i)) != 0)
        {
            if (LastPushIsNum == true || LastPushIsParClose == true)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            _operationList.push_back(new NumToken(num));
            LastPushIsNum = true;
            LastPushIsOp = false;
            LastPushIsParOpen = false;
            LastPushIsParClose = false;
        }
        else if (_input[i] == '+' || _input[i] == '-' || _input[i] == '/' || _input[i] == '*')
        {
            if (LastPushIsNum == false && LastPushIsParClose == false)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            if (LastPushIsOp == true || LastPushIsParOpen == true)               
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            _operationList.push_back(new OpToken(_input[i]));
            LastPushIsNum = false;
            LastPushIsOp = true;
            LastPushIsParOpen = false;
            LastPushIsParClose = false;
        }
        else if (_input[i] == '(')
        {           
            if (LastPushIsNum == true || LastPushIsParClose == true)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            par_match++;
            _operationList.push_back(new ParOpenToken());
            LastPushIsNum = false;
            LastPushIsOp = false;
            LastPushIsParOpen = true;
            LastPushIsParClose = false;
        }
        else if (_input[i] == ')')
        {
            if (par_match == 0 || LastPushIsOp == true || LastPushIsParOpen == true)
                throw (Calculator::InvalidOperationException::InvalidOperationException());
            par_match--;
            _operationList.push_back(new ParCloseToken());
            LastPushIsNum = false;
            LastPushIsOp = false;
            LastPushIsParOpen = false;
            LastPushIsParClose = true;
        }
        i++;
    }
    if (par_match != 0 || LastPushIsOp == true)
        throw (Calculator::InvalidOperationException::InvalidOperationException());
    std::cout << "Tokens:";
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