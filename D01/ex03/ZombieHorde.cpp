/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:59:04 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/04 15:32:56 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _nb(N)
{
	int	i;
	int	r;

	std::cout << "Zombie Horde appears" << std::endl;
	i = 0;
	std::srand(std::time(NULL));
	_horde = new Zombie[N];
	while (i < N)
	{
		r = rand() % 10;
		_horde[i].initZombie(_nameTab[r], "hungry");
		i++;
	}
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _horde;
	std::cout << "Zombie Horde rekt" << std::endl;
	return ;
}

void	ZombieHorde::announce(void) const
{
	int	i;

	i = 0;
	while (i < this->_nb)
	{
		_horde[i].announce();
		i++;	
	}
}

std::string	ZombieHorde::_nameTab[10] = {"Evil Ash", "Ed", "Michael", "Jackson", "Zom", "Shaun", "Brian", "Jesus", "Shane", "Wade"};
