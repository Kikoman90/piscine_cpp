/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 05:22:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/24 05:22:24 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type)
{
    return ;
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::~Enemy(void)
{
    return ;
}

Enemy               &Enemy::operator=(Enemy const &rhs)
{
    if (this != &rhs)
    {
        this->_hp = getHP();
        this->_type = getType();
    }
    return (*this);
}

void                Enemy::takeDamage(int dmg)
{
    if (dmg > 0)
        this->_hp -= dmg;
    if (this->_hp < 0)
        this->_hp = 0;
}

std::string const   Enemy::getType(void) const
{
    return (this->_type);
}

int                 Enemy::getHP(void) const
{
    return (this->_hp);
}

void                Enemy::setType(std::string const & type)
{
    this->_type = type;
}

void                Enemy::setHP(int hp)
{
    this->_hp = hp;
}
