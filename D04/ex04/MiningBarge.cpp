/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:53:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:02:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
    _tab[0] = NULL;
    _tab[1] = NULL;
    _tab[2] = NULL;
    _tab[3] = NULL;
}

MiningBarge::MiningBarge(MiningBarge const &src)
{
    *this = src;
}

MiningBarge::~MiningBarge(void)
{
    _freeTab();
    return ;
}

MiningBarge             &MiningBarge::operator=(MiningBarge const &rhs)
{
    int     i;

    i = 0;
    if (this != &rhs)
    {
        this->_freeTab();
        while (i < 4)
        {
            if (rhs.getTab(i))
                this->_tab[i] = rhs.getTab(i);
            i++;
        }
    }
    return (*this);
}

void                    MiningBarge::equip(IMiningLaser *laser)
{
    int     i;

    i = 0;
    while (i < 4 && this->_tab[i])
        i++;
    if (i < 4)
        this->_tab[i] = laser;
}

void                    MiningBarge::mine(IAsteroid *ast) const
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (this->_tab[i])
            this->_tab[i]->mine(ast);
        i++;
    }
}

void                    MiningBarge::_freeTab(void)
{
    int     i;

    i = 0;
    while (i < 4)
    {
        if (this->_tab[i])
        {
            delete this->_tab[i];
            this->_tab[i] = NULL;
        }
        i++;
    }
}

IMiningLaser            *MiningBarge::getTab(int idx) const
{
    return (this->_tab[idx]);
}