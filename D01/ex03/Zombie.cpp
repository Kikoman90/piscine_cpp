/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:38:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 15:43:09 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie comes out of his grave" << std::endl;
	return ;
}

void	Zombie::initZombie(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type
		<< ")> Braiiiiiiiiinnnnssssssssss..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "RIP " << this->_name << std::endl;
	return;
}
