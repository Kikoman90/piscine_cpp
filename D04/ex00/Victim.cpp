/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:21:34 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:21:35 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string const name) : _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src)
{
    *this = src;
}

Victim::~Victim(void)
{
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

Victim        &Victim::operator=(Victim const &rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
    return (*this);
}

std::string     Victim::getName(void) const
{
    return (_name);
}

void            Victim::setName(std::string const name)
{
    this->_name = name;
}

void            Victim::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream    &operator<<(std::ostream &o, Victim const &rhs)
{
    o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
    return (o);
}
