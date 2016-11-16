/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:17:02 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 17:51:29 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent event = ZombieEvent();
	ZombieEvent event2 = ZombieEvent();
	event.setZombieType("slow");
	event2.setZombieType("gross");

	Zombie *z1 = event.newZombie("Planet");
	Zombie *z2 = event.newZombie("Terror");
	Zombie *z3 = event.randomChump();
	Zombie *z4 = event.randomChump();
	Zombie *z5 = event.randomChump();

	Zombie *z6 = event2.randomChump();
	Zombie *z7 = event2.randomChump();
	Zombie *z8 = event2.randomChump();

	z1->announce();
	z2->announce();
	z3->announce();
	z4->announce();
	z5->announce();

	z6->announce();
	z7->announce();
	z8->announce();

	delete z1;
	delete z2;
	delete z3;
	delete z4;
	delete z5;
	delete z6;
	delete z7;
	delete z8;

	return (0);
}
