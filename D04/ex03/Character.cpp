/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:46:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/01 18:12:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const name) : _name(name)
{
    this->_inv[0] = NULL;
    this->_inv[1] = NULL;
    this->_inv[2] = NULL;
    this->_inv[3] = NULL;
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character(void)
{
    _freeInv();
    return ;
}

Character               &Character::operator=(Character const &rhs)
{
    int i;

    i = 0;
    if (this != &rhs)
    {
        this->_freeInv();
        this->_name = rhs.getName();
        while (i < 4)
        {
            if (rhs.getInv(i))
                this->_inv[i] = rhs.getInv(i);
            i++;
        }
    }
    return (*this);
}

std::string const       &Character::getName() const
{
    return (this->_name);
}

AMateria                *Character::getInv(int idx) const
{
    return (this->_inv[idx]);
}

void                    Character::equip(AMateria *m)
{
    int     i;

    i = 0;
    while (i < 4 && this->_inv[i] != NULL)
        i++;
    if (i < 4)
        this->_inv[i] = m;
}

void                    Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->_inv[idx] = NULL;
}

void                    Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx <= 3) && this->_inv[idx])
        this->_inv[idx]->use(target);
}

void                    Character::_freeInv(void)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (this->_inv[i])
        {
            delete this->_inv[i];
            this->_inv[i] = NULL;
        }
        i++;
    }
}