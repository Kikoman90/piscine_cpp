/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:20:08 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:58:44 by fsidler          ###   ########.fr       */
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

Calculator                          &Calculator::operator=(Calculator const &rhs)
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

void                                Calculator::_print_list(std::vector<IToken*> const &vec) const
{
    for (std::vector<IToken*>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << (*it)->display();
    std::cout << std::endl;
}

int		                            Calculator::_my_atoi(const char *str, unsigned int *k)
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

unsigned int                        Calculator::_getMaxNumWidth() const
{
    unsigned int        length = 0;
    std::stringstream   sstream;

    for (std::vector<IToken*>::const_iterator it = _postfixList.begin(); it != _postfixList.end(); ++it)
    {
        sstream.str("");
        NumToken    *num_token = dynamic_cast<NumToken*>(*it);
        if (num_token)
        {
            sstream << num_token->getNum();
            length = (sstream.str().length() > length) ? sstream.str().length() : length;
        }
    }
    return (length + 7);
}

void                                Calculator::tokenize()
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

bool                                Calculator::_opPriority(OpToken const *op1, OpToken const *op2) const
{
    char    ch_op1 = op1->getOp();
    char    ch_op2 = op2->getOp();

    if ((ch_op1 == '+' || ch_op1 == '-') && (ch_op2 == '*' || ch_op2 == '/'))
        return (false);
    return (true);
}

std::vector<IToken*>::iterator      Calculator::_convertToPostfix(std::vector<IToken*>::iterator &begin)
{
    std::vector<IToken*>::iterator  it;
    OpToken                         *cur_op = NULL;
    OpToken                         *last_op = NULL;

    for (it = begin ; it != _operationList.end(); ++it)
    {
        NumToken    *num_token = dynamic_cast<NumToken*>(*it);
        if (num_token)
            _postfixList.push_back((*it)->clone());
        OpToken     *op_token = dynamic_cast<OpToken*>(*it);
        if (op_token)
        {
            if (!cur_op)
                cur_op = op_token;
            else if (_opPriority(cur_op, op_token) == true)
            {
                _postfixList.push_back(cur_op->clone());
                cur_op = op_token;
            }
            else if (_opPriority(cur_op, op_token) == false)
            {
                last_op = cur_op;
                cur_op = op_token;
            }
            if (last_op && _opPriority(last_op, cur_op) == true)
            {
                _postfixList.push_back(last_op->clone());
                last_op = NULL;
            }
        }
        ParOpenToken    *par_open_token = dynamic_cast<ParOpenToken*>(*it);
        if (par_open_token)
            it = _convertToPostfix(++it);
        else
        {
            ParCloseToken   *par_close_token = dynamic_cast<ParCloseToken*>(*it);
            if (par_close_token)
                break;
        }
    }
    if (cur_op)
        _postfixList.push_back(cur_op->clone());
    if (last_op)
        _postfixList.push_back(last_op->clone());
    return (it);
}

void                                Calculator::result()
{
    std::vector<IToken*>::iterator  begin = _operationList.begin();
    _convertToPostfix(begin);
    std::cout << "Postfix:";
    _print_list(_postfixList);

    int                 num;
    unsigned int        length = _getMaxNumWidth();
    MutantStack<int>    operation_stack;
    for (std::vector<IToken*>::const_iterator it = _postfixList.begin(); it != _postfixList.end(); ++it)
    {
        NumToken    *num_token = dynamic_cast<NumToken*>(*it);
        if (num_token)
        {
            num_token->completeDisplay(length);
            num = num_token->getNum();
            operation_stack.push(num);
        }
        OpToken     *op_token = dynamic_cast<OpToken*>(*it);
        if (op_token)
        {
            op_token->completeDisplay(length);
            num = operation_stack.top();
            operation_stack.pop();
            num = op_token->operation(operation_stack.top(), num);
            operation_stack.pop();
            operation_stack.push(num);
        }
        for (MutantStack<int>::const_iterator it2 = operation_stack.begin(); it2 != operation_stack.end(); ++it2)
            std::cout << " " << *it2;
        std::cout << ']' << std::endl;
    }
    std::cout << "Result: " << operation_stack.top() << std::endl;
    operation_stack.pop();
}

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