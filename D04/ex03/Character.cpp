/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:46:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/15 18:31:37 by fsidler          ###   ########.fr       */
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
    int     i;

    i = 0;
    this->_name = src.getName();
    this->_inv[0] = NULL;
    this->_inv[1] = NULL;
    this->_inv[2] = NULL;
    this->_inv[3] = NULL;
    while (i < 4)
    {
        if (src._inv[i])
            this->equip(src._inv[i]->clone());
        i++;
    }
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
            if (rhs._inv[i])
                this->equip(rhs._inv[i]->clone());
            i++;
        }
    }
    return (*this);
}

std::string const       &Character::getName() const
{
    return (this->_name);
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