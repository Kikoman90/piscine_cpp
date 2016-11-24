/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:32 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:33 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
    return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src)
{
    *this = src;
}

PlasmaRifle::~PlasmaRifle(void)
{
    return ;
}

PlasmaRifle     &PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setAPCost(rhs.getAPCost());
        this->setDamage(rhs.getDamage());
    }
    return (*this);
}

void            PlasmaRifle::attack(void) const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
