/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:38:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 16:25:02 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	std::cout << this->_name << " the zombie comes out of his grave" << std::endl;
	return ;
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
