/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:42:02 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/27 18:53:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mindopen.hpp"

Mindopen::Mindopen(char *str) : _fileName(str) {}

Mindopen::Mindopen(Mindopen const &src)
{
    _fileName = src._fileName;
    _container = src._container;
}

Mindopen::~Mindopen() {} //DELETE ALL INSTRUCTIONS}

Mindopen        &Mindopen::operator=(Mindopen const &rhs)
{
    if (this != &rhs)
    {
        //DELETE ALL INSTRUCTIONS
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