/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:29:25 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:17:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    return ;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
    *this = src;
}

Cure::~Cure(void)
{
    return ;
}

Cure             &Cure::operator=(Cure const &rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return (*this);
}

AMateria        *Cure::clone(void) const
{
    return ((AMateria*)new Cure(*this));
}

void            Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    this->increaseXP();
}