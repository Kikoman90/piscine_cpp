/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:50:28 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:46:54 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpToken.hpp"

OpToken::OpToken(char op) : _op(op) {}

OpToken::OpToken(OpToken const &src) : _op(src._op) {}

OpToken::~OpToken() {}

OpToken         &OpToken::operator=(OpToken const &rhs)
{
    if (this != &rhs)
        _op = rhs._op;
    return (*this);
}

IToken          *OpToken::clone() const
{
    IToken  *clone;

    clone = new OpToken(*this);
    return (clone);
}

char            OpToken::getOp() const { return (_op); }

std::string     OpToken::display() const
{
    std::stringstream   sstream;

    sstream << " Op(" << _op << ')';
    return (sstream.str());
}

void            OpToken::completeDisplay(unsigned int length) const
{
    if (_op == '+')
        std::cout << '[' << std::left << std::setw(length) << display() << "| OP Add       | ST";
    else if (_op == '-')
        std::cout << '[' << std::left << std::setw(length) << display() << "| OP Substract | ST";
    else if (_op == '*')
        std::cout << '[' << std::left << std::setw(length) << display() << "| OP Multiply  | ST";
    else if (_op == '/')
        std::cout << '[' << std::left << std::setw(length) << display() << "| OP Divide    | ST";
}

int             OpToken::operation(int n1, int n2) const
{
    int result = 0;

    if (_op == '+')
        result = n1 + n2;
    else if (_op == '-')
        result = n1 - n2;
    else if (_op == '*')
        result = n1 * n2;
    else if (_op == '/')
        result = n1 / n2;
    return (result);
}