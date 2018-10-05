/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:13 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/05 13:06:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL)
{
    return ;
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character(void)
{
    return ;
}

Character           &Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_ap = rhs.getAP();
        this->_weapon = rhs.getWeapon();
    }
    return (*this);
}

void                Character::recoverAP(void)
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void                Character::equip(AWeapon *weap)
{
    this->_weapon = weap;
}

void                Character::attack(Enemy *enem)
{
    if (enem && this->_weapon != NULL && this->_ap >= this->_weapon->getAPCost())
    {
        std::cout   << _name << " attacks " << enem->getType() << " with a "
                    << this->_weapon->getName() << std::endl;
        this->_ap -= this->_weapon->getAPCost();
        this->_weapon->attack();
        enem->takeDamage(this->_weapon->getDamage());
        if (enem->getHP() <= 0)
            delete enem;
    }
}

std::string const   &Character::getName(void) const
{
    return (_name);
}

int                 Character::getAP(void) const
{
    return (_ap);
}

AWeapon             *Character::getWeapon(void) const
{
    return (_weapon);
}

std::ostream        &operator<<(std::ostream &o, Character const &rhs)
{
    if (rhs.getWeapon() == NULL)
        std::cout << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    else
        std::cout << rhs.getName() << " has " << rhs.getAP() << " AP and wields a "
        << rhs.getWeapon()->getName() << std::endl;
    return (o);
}
