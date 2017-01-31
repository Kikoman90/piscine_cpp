/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParCloseToken.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:54:41 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 18:56:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParCloseToken.hpp"

ParCloseToken::ParCloseToken() {}

ParCloseToken::ParCloseToken(ParCloseToken const &src) { *this = src; }

ParCloseToken::~ParCloseToken() {}

ParCloseToken   &ParCloseToken::operator=(ParCloseToken const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

IToken          *ParCloseToken::clone() const
{
    IToken  *clone;

    clone = new ParCloseToken(*this);
    return (clone);
}

void            ParCloseToken::display() const { std::cout << " ParClose"; }