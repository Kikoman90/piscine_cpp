#include "Squad.hpp"

Squad::Squad(void) : _list(NULL)
{
    return ;
}

Squad::Squad(Squad const &src)
{
    _freeUnitList();
    *this = src;
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
            this->push(tmp->SpaceMarine);
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
    bool        alreadyExists = false;

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
        if (SpcMarine && tmp->SpaceMarine == SpcMarine)
            alreadyExists = true;
        _list = _list->next;
    }
    if (SpcMarine && alreadyExists != true)
    {
        newUnit->index = (_list->index + 1);
        _list->next = newUnit;
        _list = tmp;

    }
    return (this->getCount());
}

ISpaceMarine            *Squad::getUnit(int index)
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
}