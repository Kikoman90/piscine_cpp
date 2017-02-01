/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:50:28 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/01 23:35:25 by fsidler          ###   ########.fr       */
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

void            OpToken::display() const { std::cout << " Op(" << _op << ")"; }