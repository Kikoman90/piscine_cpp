/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:55:01 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/21 19:55:03 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void    HumanB::setWeapon(Weapon::Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
