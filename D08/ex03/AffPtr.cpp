/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AffPtr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:41:03 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:42:48 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AffPtr.hpp"

AffPtr::AffPtr() {}

AffPtr::AffPtr(AffPtr const &src) { *this = src; }

AffPtr::~AffPtr() {}

AffPtr                                  &AffPtr::operator=(AffPtr const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

IInstruction                            *AffPtr::clone() const { return ((IInstruction*)new AffPtr(*this)); }

std::vector<IInstruction*>::iterator    AffPtr::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    static_cast<void>(c);
    std::cout << **ptr;
    return (it);
}