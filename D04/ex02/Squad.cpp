/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:38 by fsidler           #+#    #+#             */
/*   Updated: 2018/10/05 13:11:49 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void) : _list(NULL)
{
    this->_list = NULL;
    return ;
}

Squad::Squad(Squad const &src)
{
    t_unit  *tmp = src._list;

    this->_list = NULL;
    while (tmp)
    {
        this->push(tmp->SpaceMarine->clone());
        tmp = tmp->next;
    }
}

Squad::~Squad(void)
{
    _freeUnitList();
}

Squad                  &Squad::operator=(Squad const &rhs)
{
    t_unit      *tmp = rhs._list;

    if (this != &rhs)
    {
        this->_freeUnitList();
        while (tmp)
        {
            this->push(tmp->SpaceMarine->clone());
            tmp = tmp->next;
        }
    }
    return (*this);
}

int                     Squad::getCount(void) const
{
    int         count;
    t_unit      *tmp = this->_list;

    count = 0;
    while (tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return (count);
}

int                     Squad::push(ISpaceMarine *SpcMarine)
{
    t_unit      *tmp = this->_list;
    t_unit      *newUnit = new t_unit();
    bool        doesNotAlreadyExist = true;

    if (!SpcMarine)
        return (this->getCount());
    newUnit->SpaceMarine = SpcMarine;
    newUnit->next = NULL;
    if (!_list)
    {
        newUnit->index = 0;
        _list = newUnit;
        return (this->getCount());
    }
    while (_list->next)
    {
        if (!SpcMarine || _list->SpaceMarine == SpcMarine)
            doesNotAlreadyExist = false;
        _list = _list->next;
    }
    if (SpcMarine && doesNotAlreadyExist != false)
    {
        newUnit->index = (_list->index + 1);
        _list->next = newUnit;
    }
    _list = tmp;
    return (this->getCount());
}

ISpaceMarine            *Squad::getUnit(int index) const
{
    t_unit    *tmp = this->_list;

    while (tmp)
    {
        if (tmp->index == index)
            return(tmp->SpaceMarine);
        tmp = tmp->next;
    }
    return (NULL);
}

void                    Squad::_freeUnitList(void)
{
    t_unit    *first;
    t_unit    *tmp;

    first = this->_list;
    while (first != NULL)
    {
        tmp = first->next;
        delete first->SpaceMarine;
        delete first;
        first = tmp;
    }
    this->_list = NULL;
}
