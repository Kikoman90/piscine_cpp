/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumToken.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:45 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 18:48:32 by fsidler          ###   ########.fr       */
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

void            NumToken::display() const { std::cout << " Num(" << _num << ")"; }