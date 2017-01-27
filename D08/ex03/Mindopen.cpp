/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:42:02 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 19:45:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mindopen.hpp"

Mindopen::Mindopen(char *str) : _fileName(str) {}

Mindopen::Mindopen(Mindopen const &src) : _fileName(src._fileName)
{
    for (std::vector<IInstruction*>::const_iterator it = src._container.begin(); it != src._container.end(); ++it)
        _container.push_back((*it)->clone());
}

Mindopen::~Mindopen()
{
    for (std::vector<IInstruction*>::iterator it = _container.begin(); it != _container.end(); ++it)
        delete (*it);
}

Mindopen        &Mindopen::operator=(Mindopen const &rhs)
{
    if (this != &rhs)
    {
        for (std::vector<IInstruction*>::iterator it = _container.begin(); it != _container.end(); ++it)
            delete (*it);
        for (std::vector<IInstruction*>::const_iterator it = rhs._container.begin(); it != rhs._container.end(); ++it)
            _container.push_back((*it)->clone());
        _fileName = rhs._fileName;
        _container = rhs._container;
    }
    return (*this);
}

void            Mindopen::readStr()
{
    std::ifstream           file(_fileName);
    std::stringstream       read;
    std::string             str;
    std::string::iterator   it;

    read << file.rdbuf();
    str = read.str();
    for (it = str.begin(); it != str.end(); ++it)
	{
        if (*it == '^')
            _container.push_back(new IncValue());
        else if (*it == 'v')
            _container.push_back(new DecValue());
        else if (*it == '*')
            _container.push_back(new IncPtr());
        else if (*it == '&')
            _container.push_back(new DecPtr());
        else if (*it == '(')
            _container.push_back(new OpenLoop());
        else if (*it == ')')
            _container.push_back(new CloseLoop());
		else if (*it == '!')
            _container.push_back(new AffPtr());
    }
    file.close();
}

void            Mindopen::executeInstructions()
{
    char    *ptr = new char[2048];
    
    for (std::vector<IInstruction*>::iterator it = _container.begin(); it != _container.end(); ++it)
        it = (*it)->execute(it, _container, &ptr);
}