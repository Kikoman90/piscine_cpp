/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:23:03 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:23:04 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src)
{
    *this = src;
}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh ..." << std::endl;
}

SuperMutant     &SuperMutant::operator=(SuperMutant const &rhs)
{
    if (this != &rhs)
    {
        this->setType(rhs.getType());
        this->setHP(rhs.getHP());
    }
    return (*this);
}

void            SuperMutant::takeDamage(int dmg)
{
    dmg -= 3;
    if (dmg > 0)
        this->setHP(this->getHP() - dmg);
    if (this->getHP() < 0)
        this->setHP(0);
}
