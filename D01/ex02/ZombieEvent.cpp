/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:00:16 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 17:56:18 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	std::srand(std::time(NULL));
	std::cout << "Zombie event begins" << std::endl;
	this->_zombieType = "brainthirsty";
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "End of event" << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_zombieType = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->_zombieType));
}

Zombie	*ZombieEvent::randomChump(void)
{
	int		i;

	i = rand() % 10;
	return (new Zombie(ZombieEvent::_nameTab[i], this->_zombieType));
}

std::string	ZombieEvent::_nameTab[10] = {"Evil Ash", "Ed", "Michael", "Jackson", "Zom", "Shaun", "Brian", "Jesus", "Shane", "Wade"};
