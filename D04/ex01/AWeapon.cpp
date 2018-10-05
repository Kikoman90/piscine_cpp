/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:04 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/05 13:01:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{
    return ;
}

AWeapon::AWeapon(AWeapon const &src)
{
    *this = src;
}

AWeapon::~AWeapon(void)
{
    return ;
}

AWeapon				&AWeapon::operator=(AWeapon const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_apcost = rhs.getAPCost();
        this->_damage = rhs.getDamage();
    }
    return (*this);
}

std::string const	&AWeapon::getName(void) const
{
    return (_name);
}

int					AWeapon::getAPCost(void) const
{
    return (_apcost);
}

int					AWeapon::getDamage(void) const
{
    return (_damage);
}

void				AWeapon::setName(std::string const &name)
{
    this->_name = name;
}

void				AWeapon::setDamage(int dmg)
{
    this->_damage = dmg;
}

void				AWeapon::setAPCost(int apc)
{
    this->_apcost = apc;
}
