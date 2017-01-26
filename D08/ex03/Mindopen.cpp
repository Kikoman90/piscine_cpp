/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:42:02 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/26 19:03:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mindopen.hpp"

Mindopen::Mindopen(char *str) : _str(strdup(str)) {}

Mindopen::Mindopen(Mindopen const &src)
{
    _str = strdup(src._str);
    _container = src._container;
}

Mindopen::~Mindopen() { delete _str; } //DELETE ALL INSTRUCTIONS}

Mindopen        &Mindopen::operator=(Mindopen const &rhs)
{
    if (this != &rhs)
    {
        //DELETE ALL INSTRUCTIONS
        delete _str;
        _str = rhs._str;
        _container = rhs._container;
    }
    return (*this);
}

void            Mindopen::readStr()
{
    unsigned int        i;

	i = 0;
	while (_str[i] != 0)
	{
        if (_str[i] == '+')
            _container.push_back(new IncValue());
        else if (_str[i] == '-')
            _container.push_back(new DecValue());
        else if (_str[i] == '>')
            _container.push_back(new IncPtr());
        else if (_str[i] == '<')
            _container.push_back(new DecPtr());
        else if (_str[i] == '[')
            _container.push_back(new OpenLoop());
        else if (_str[i] == ']')
            _container.push_back(new CloseLoop());
		else if (_str[i] == '.')
            _container.push_back(new AffPtr());
        i++;
    }
}

void            Mindopen::executeInstructions()
{
    char    *ptr = new char[2048];
    
    for (std::vector<IInstruction*>::iterator it = _container.begin(); it != _container.end(); ++it)
        it = (*it)->execute(it, _container, &ptr);
}