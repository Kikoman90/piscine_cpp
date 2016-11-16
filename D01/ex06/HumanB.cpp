/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:44:01 by jfortin           #+#    #+#             */
/*   Updated: 2016/11/07 15:14:11 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void    HumanB::setWeapon(Weapon::Weapon &weapon)
{
    HumanB::weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
