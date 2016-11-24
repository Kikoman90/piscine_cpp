/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:45 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
    return ;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src)
{
    *this = src;
}

PowerFist::~PowerFist(void)
{
    return ;
}

PowerFist       &PowerFist::operator=(PowerFist const &rhs)
{
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setAPCost(rhs.getAPCost());
        this->setDamage(rhs.getDamage());
    }
    return (*this);
}

void            PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
