/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:05:39 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 14:03:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(float height, int age, std::string name, std::string color) : _height(height), _age(age), _name(name), _color(color)
{
	std::cout << this->_name << " is born" << std::endl;
	this->_nbPony++;
	return ;
}

void			Pony::displayPonyInfos(void) const
{
	std::cout << "name: " << this->_name << " | color: " << this->_color
		<< " | age: " << this->_age << " |height: "
		<< this->_height << std::endl;
}

unsigned int	Pony::getNbPony(void)
{
	return (Pony::_nbPony);
}

Pony::~Pony(void)
{
	std::cout << "RIP " << this->_name << std::endl;
	this->_nbPony--;
	return;
}

unsigned int	Pony::_nbPony = 0;
