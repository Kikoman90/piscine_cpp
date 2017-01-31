/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncPtr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:48:35 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/31 18:42:51 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncPtr.hpp"

IncPtr::IncPtr() {}

IncPtr::IncPtr(IncPtr const &src) { *this = src; }

IncPtr::~IncPtr() {}

IncPtr                                  &IncPtr::operator=(IncPtr const &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

IInstruction                            *IncPtr::clone() const
{
    IInstruction    *clone;

    clone = new IncPtr(*this);
    return (clone);
}

std::vector<IInstruction*>::iterator    IncPtr::execute(std::vector<IInstruction*>::iterator &it, std::vector<IInstruction*> &c, char **ptr) const
{
    static_cast<void>(c);
    *ptr += 1;
    return (it);
}