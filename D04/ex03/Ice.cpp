/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:36:42 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:17:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    return ;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
    *this = src;
}

Ice::~Ice(void)
{
    return ;
}

Ice             &Ice::operator=(Ice const &rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return (*this);
}

AMateria        *Ice::clone(void) const
{
    return ((AMateria*)new Ice(*this));
}

void            Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    this->increaseXP();
}