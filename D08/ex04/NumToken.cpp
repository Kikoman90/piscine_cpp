/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumToken.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:45 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:46:34 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumToken.hpp"

NumToken::NumToken(int num) : _num(num) {}

NumToken::NumToken(NumToken const &src) : _num(src._num) {}

NumToken::~NumToken() {}

NumToken        &NumToken::operator=(NumToken const &rhs)
{
    if (this != &rhs)
        _num = rhs._num;
    return (*this);
}

IToken          *NumToken::clone() const
{
    IToken  *clone;

    clone = new NumToken(*this);
    return (clone);
}

int             NumToken::getNum() const { return (_num); }

std::string     NumToken::display() const
{
    std::stringstream   sstream;

    sstream << " Num(" << _num << ')';
    return (sstream.str());
}

void            NumToken::completeDisplay(unsigned int length) const { std::cout << '[' << std::left << std::setw(length) << display() << "| OP Push      | ST"; }