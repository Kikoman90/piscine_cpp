/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpenToken.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:58:03 by fsidler           #+#    #+#             */
/*   Updated: 2017/02/02 01:42:38 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParOpenToken.hpp"

ParOpenToken::ParOpenToken() {}

ParOpenToken::ParOpenToken(ParOpenToken const &src) { *this = src; }

ParOpenToken::~ParOpenToken() {}

ParOpenToken    &ParOpenToken::operator=(ParOpenToken const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

IToken          *ParOpenToken::clone() const
{
    IToken  *clone;

    clone = new ParOpenToken(*this);
    return (clone);
}

std::string     ParOpenToken::display() const { return (" ParOpen"); }