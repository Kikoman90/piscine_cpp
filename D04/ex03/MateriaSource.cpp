/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:41:19 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/02 16:03:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    //this->_mat = new **AMateria;
    this->_mat[0] = NULL;
    this->_mat[1] = NULL;
    this->_mat[2] = NULL;
    this->_mat[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    *this = src;
}

MateriaSource::~MateriaSource(void)
{
    _freeMat();
    return ;
}

MateriaSource           &MateriaSource::operator=(MateriaSource const &rhs)
{
    int i;

    i = 0;
    if (this != &rhs)
    {
        this->_freeMat();
        while (i < 4)
        {
            if (rhs.getMat(i))
                this->_mat[i] = rhs.getMat(i);
            i++;
        }
    }
    return (*this);
}

void                    MateriaSource::learnMateria(AMateria *m)
{
    int i;

    i = 0;
    while (i < 4 && this->_mat[i])
        i++;
    if (i < 4)
        this->_mat[i] = m->clone();
}

AMateria                *MateriaSource::createMateria(std::string const &type)
{
    int     i;

    i = 0;
    while (i < 4 && this->_mat[i])
    {
        if (this->_mat[i]->getType().compare(type) == 0)
            return (this->_mat[i]->clone());
        i++;
    }
    return (NULL);
}

void                    MateriaSource::_freeMat()
{
    int     i;

    i = 0;
    while (i < 4)
    {
        if (this->_mat[i])
        {
            delete this->_mat[i];
            this->_mat[i] = NULL;
        }
        i++;
    }
}

AMateria                *MateriaSource::getMat(int idx) const
{
    return (this->_mat[idx]);
}