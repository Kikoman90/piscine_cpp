/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:57:56 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 18:43:13 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"
#include <time.h>

CentralBureaucracy::CentralBureaucracy() : _queue(NULL), _blockCount(0), _bureaucratCount(0)
{
    srand(time(NULL));
    return ;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src)
{
    *this = src;
}

CentralBureaucracy::~CentralBureaucracy()
{
    _freeQueue();
}

CentralBureaucracy          &CentralBureaucracy::operator=(CentralBureaucracy const &rhs)
{
    unsigned int    i;
    t_targetQueue   *targ = rhs._queue;

    i = rhs._blockCount;
    if (this != &rhs)
    {
        this->_blockCount = rhs._blockCount;
        this->_bureaucratCount = rhs._bureaucratCount;
        _freeQueue();
        while (i--)
            this->_blocks[i] = rhs._blocks[i];
        while (targ)
        {
            queueUp(targ->target);
            targ = targ->next; 
        }
    }
    return (*this);
}

void                            CentralBureaucracy::queueUp(std::string target)
{
    this->_queue = CentralBureaucracy::pushTarget(target);
}

t_targetQueue                   *CentralBureaucracy::pushTarget(std::string target)
{
    t_targetQueue   *tmp = this->_queue;
    t_targetQueue   *newUnit = new t_targetQueue();

    newUnit->target = target;
    newUnit->next = NULL;
    if (!_queue)
    {
        _queue = newUnit;
        return (_queue);
    }
    while (_queue->next)
        _queue = _queue->next;
    _queue->next = newUnit;
    return (tmp);
}

void                            CentralBureaucracy::feed(Bureaucrat &bureaucrat)
{
    if (_bureaucratCount < 40)
    {
        if ((_bureaucratCount % 2) == 0)
            _blocks[_blockCount].setSigner(bureaucrat);
        else
        {
            _blocks[_blockCount].setExecutor(bureaucrat);
            _blocks[_blockCount].setIntern(*(new Intern));
            _blockCount++;
        }
        _bureaucratCount++;
    }
}

void                            CentralBureaucracy::doBureaucracy() const
{
    t_targetQueue   *tmp = _queue;
    std::string     formTab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int     i;
    int     j;

    while (tmp)
    {
        i = rand() % (_blockCount * 10);
        i /= 10;
        j = rand() % 3;
        try
        {
            _blocks[i].doBureaucracy(formTab[j], tmp->target);
        }
        catch (std::exception &e)
	    {
		    std::cout << e.what() << std::endl;
	    }
        tmp = tmp->next;
    }
}

void                            CentralBureaucracy::_freeQueue()
{
    t_targetQueue   *tmp;
    t_targetQueue   *first = _queue;

    while (first)
    {
        tmp = first->next;
        delete first;
        first = tmp;
    }
    _queue = NULL;
}