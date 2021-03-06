/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:21:15 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:21:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const name, std::string const title) : _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
    *this = src;
}

Sorcerer::~Sorcerer(void)
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer        &Sorcerer::operator=(Sorcerer const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_title = rhs.getTitle();
    }
    return (*this);
}

void            Sorcerer::polymorph(Victim const &target) const
{
    target.getPolymorphed();
}

std::string     Sorcerer::getName(void) const
{
    return (_name);
}

std::string     Sorcerer::getTitle(void) const
{
    return (_title);
}

std::ostream    &operator<<(std::ostream &o, Sorcerer const &rhs)
{
    o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return (o);
}
